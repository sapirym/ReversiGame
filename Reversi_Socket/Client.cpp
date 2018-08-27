

#include "Client.h"
#include "Point.h"
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include <vector>
using namespace std;

Client::Client(const char* serverIP,int serverPort, Board& b):
        serverIP(serverIP),serverPort(serverPort),clientSocket(0) {
    board= b;
    player =new HumanLogic(board);
    firstLoop=-1;
    endGame=0;
}

Client::~Client(){
    delete (player);
}


void Client::connectToServer() {
// Create a socket point
    int flagType;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening s------------------ocket";
    }
    struct in_addr address;
    if(!inet_aton(serverIP, &address)){
        throw "Cant parse IP address";
    }
// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
    if(server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address,sizeof(address));
    serverAddress.sin_family= AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr
            , server->h_length);
    // converts values between host and network byte orders
    serverAddress.sin_port=htons(serverPort);
    // Establish a connection with the TCP server
    if(connect(clientSocket, (struct sockaddr*)&serverAddress
            ,sizeof(serverAddress)) ==-1) {
        throw"Error connecting to server";
    }
    //who is the first player
    int val=-1;
    read(clientSocket, &val,sizeof(val));
    if(val==0)
        cout<<"waiting for other player to join.."<<endl;
    if(val ==-1){
        throw "Error with val reading.";
    }
    //the type of player- according to the connection order
    read(clientSocket, &flagType,sizeof(flagType));
    firstLoop=val;
    cout<<"player: "<<flagType<<" Connected to server"<<endl;
    cout<<"your type is: "<<flagType<<endl;
    if(flagType ==1){
        type = 'X';
        otherType = 'O';
    } else{
        type = 'O';
        otherType = 'X';
    }
}

void Client::startGame(){
    int n;
    if (n == -1) {
        throw "Error writing arg to socket";
    }    while(true){
        if(endGame==1)

            return;
        sendPoint(firstLoop);
        if(firstLoop==0){
            firstLoop =1;
        }
    }
}

void Client::sendPoint(int firstTurn) {
    int x,y, n;
    // Write the point arguments to the socket
    if(firstTurn !=0 && !board.fullBoard()) {
        cout<<"waiting for other player's move."<<endl<<endl;
        n = read(clientSocket, &x, sizeof(x));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
        n = read(clientSocket, &y, sizeof(y));
        if (n == -1) {
            throw "Error writing arg2 to socket";
        }
        if(x==-2&&y==-2){
            cout<<"the other player didn't make any move."<<endl;
        }else if(x==-3&&y==-3){
            cout<<"game over."<<endl;
            n = write(clientSocket, &x,sizeof(x));
            n = write(clientSocket, &y,sizeof(y));
            return;
        } else {
            vector<Point> p = player->optionCell(x - 1, y - 1, otherType, 1);
            player->updateVector(p, otherType);
            player->updateSpecificCell(x, y, otherType);
            cout << otherType << " played: (" << x << "," << y << ")" << endl;
        }
    }
    int xVal, yVal;
    if(board.fullBoard()) {
        if (board.getCountero() > board.getCounterx() ) {
            if (type == 'O')
                cout << endl << "O You are the winner!" << endl;
            else
                cout << endl << "you are the loser, O the winner!" << endl;
        }else{
            if (type == 'X')
                cout << endl << "X You are the winner!" << endl;
            else
                cout << endl << "you are the loser, X the winner!" << endl;
        }
        xVal = -3;
        yVal = -3;
        endGame =1;
    } else {
        Point result;
        result = playOneTurnClient(type);
        board.printBoard();
        // Read the result from the server
         if(result.getX()!=-2 && result.getY()!=-2) {
            // Read the result from the server
            xVal = result.getX() + 1;
            yVal = result.getY() + 1;
        } else{
            xVal = result.getX();
            yVal = result.getY();
        }
    }
    n = write(clientSocket, &xVal,sizeof(xVal));
    n = write(clientSocket, &yVal,sizeof(yVal));
    if(xVal==-3 && yVal==-3)
        return;
    if(n ==-1) {
        throw "Error reading result from socket";
    }
}

Point Client:: playOneTurnClient(char type) {
    board.printBoard();
    cout << type << ": Its your move." << endl;
    vector<Point> op;
    cout<<"Your possible moves: ";
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //send a clean cell and check is option
            if (board.getCell(i , j )->isClear()) {
                if(type == 'X') {
                    vector<Point> p = player->optionCell(i, j, type,0);
                    if (!p.empty()) {
                        //print the option
                        op.push_back(Point(i, j));
                    }
                } else{
                    vector<Point> p = player->optionCell(i,j,type,0);
                    if(!p.empty()){
                        op.push_back(Point(i,j));
                    }
                }
            }
        }
    }
    int  flag=0;
    char dummy;
    if(!op.empty()){
        do {
            int numX =0, numY=0;
            cout << endl << "Please enter your move- row col: (e.g. 3 4) ";
            cin >> numX >> numY;
            cout<<endl;
            for (int i = 0; i < op.size(); i++) {
                //if the input match to the possible move points
                if (op[i].getX() == numX-1 && op[i].getY() == numY-1) {
                    vector<Point> p = player->optionCell(numX-1,numY-1,type,1);
                    //update the choose cells
                    player->updateVector(p, type);
                    //update the cell himself
                    board.updateCell(numX,numY,type);
                    flag = 1;
                    return op[i];
                }
            }
            //if the input no good- give another chance
            if(flag==0)
                cout<<"Try again!"<<endl;
        } while(flag==0);
    }else{
        cout<<"there is no move for you this turn."<<endl;
        return Point(-2,-2);
    }
}
