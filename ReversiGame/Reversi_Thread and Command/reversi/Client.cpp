/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#include "Client.h"
#include "Point.h"
#include "SecondMenu.h"
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include <vector>
#include <cstdlib>
#include "ScreenView.h"

using namespace std;

Client::Client(const char* serverIP,int serverPort, Board& b):
        serverIP(serverIP),serverPort(serverPort),clientSocket(0) {
    board= b;
    player =new HumanLogic(board);
    firstLoop=-1;
    endGame=0;
    screen=ScreenView();
}

Client::~Client(){
    delete (player);
}


void Client::connectToServer() {
    // Create a socket point
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
    //choose the option you want to play
    SecondMenu menu;
    string choice = menu.getChoice();
    int serverAns, n;
    string stringServer;
    /*char hadas[10]="start\0";
    int stringlen = 10;
    //cout<<"hey";
    //cout<<stringlen;
    n= write(clientSocket, &stringlen,sizeof(stringlen));
    if (n == -1) {
        throw "Error writing arg to socket";
    }
    for(int i=0;i<stringlen;i++) {
        n = write(clientSocket, &hadas[i], sizeof(char));
        if (n == -1) {
            throw "Error writing arg to socket";
        }
    }*/
    int size=choice.length()+1;
    //cout<<choice<<"YOHO"<<endl;
    const char *charChoice =choice.c_str();
    //send the length of the option
    send(clientSocket, &size,sizeof(int),0);
    //send the string
    for(int i=0;i<size;i++) {
        n = write(clientSocket, &charChoice[i], sizeof(char));
        if (n == -1) {
            throw "Error writing arg to socket";
        }
    }
    //send(clientSocket, &choice,sizeof(choice),0);

    //if the choice is start
    if(choice.find("start")!=-1) {
        n = read(clientSocket, &serverAns, sizeof(serverAns));
        //if the game exist
        if(serverAns==-1){
            screen.printString("Error: there is a game with this name!");
            exit(0);
        }
        if(serverAns==1){
            screen.printString("The room is initialize.\n");
            screen.printString("Waiting for other player to join..\n");
            startGame();
        }
        if(RightValue(n))
            exit(0);
    }
    //if the choice is join
    else if(choice.find("join")!=-1){
        startGame();
    //if the choice is list
    }else if(choice.find("list_game")!=-1){
        int stringLen;
        n=read(clientSocket, &stringLen, sizeof(stringLen));
        if(stringLen==0){
            screen.printString("The list is empty!\n");
        }else {
            char *getString = new char[stringLen];
            for (int i = 0; i < stringLen; ++i) {
                n = read(clientSocket, &getString[i], sizeof(char));
            }
            string inputUser(getString);
            delete (getString);
            /*if (inputUser == "") {
                screen.printString("the list is empty!\n");
            } else {*/
                inputUser = "The list of game is:\n" + inputUser;
                screen.printString(inputUser);
        }
        /*if(RightValue(n))
            exit(-1);
        if(stringServer==""){
            screen.printString("the list is empty!\n");
        } else{
            stringServer="the list og game is:\n"+stringServer;
            screen.printString(stringServer);
        }*/
        exit(0);
    }
}

void Client::startGame(){
    int flagType;
    //who is the first player
    /*int val=-1;
    read(clientSocket, &val,sizeof(val));
    if(val==0)
        cout<<"waiting for other player to join.."<<endl;
    if(val ==-1){
        throw "Error with val reading.";
    }*/
    //the type of player- according to the connection order
    int n;
    n = read(clientSocket, &flagType,sizeof(flagType));
    if(flagType==-1) {
        screen.printString("the game you input didnt exist");
        exit(0);
    }
    //cout<<"flag type:"<<flagType<<endl;
    //screen.printStringWithMsgBefore("flag type:",flagType);
    //screen.printEnter();
    if (n == -1) {
        throw "Error writing arg to socket";
    }
    if(flagType==1)
    firstLoop=0;
    else
        firstLoop=-1;

    screen.printString("The Game start now!\n");
    if(flagType ==1){
        type = 'X';
        otherType = 'O';
    } else{
        type = 'O';
        otherType = 'X';
    }
    //cout<<"player: "<<flagType<<" Connected to server"<<endl;
    screen.printStringWithMsgBefore("player: ",otherType);
    screen.printString(" Connected to server\n");
    //cout<<"your type is: "<<flagType<<endl;
    screen.printStringWithMsgBefore("your type is: ",type);
    screen.printEnter();
    /*if(flagType ==1){
        type = 'X';
        otherType = 'O';
    } else{
        type = 'O';
        otherType = 'X';
    }*/


    while(true){
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
        screen.printString("waiting for other player's move.\n\n");
        //cout<<"waiting for other player's move."<<endl<<endl;
        n = read(clientSocket, &x, sizeof(x));
        n = read(clientSocket, &y, sizeof(y));
        if(RightValue(n))
            exit(0);
        if(x==-2&&y==-2){
            screen.printString("the other player didn't make any move.\n");
            //cout<<"the other player didn't make any move."<<endl;
        }else if(x==-3&&y==-3){
            screen.printString("Game Over.\n");
            //cout<<"game over."<<endl;
            n = write(clientSocket, &x,sizeof(x));
            n = write(clientSocket, &y,sizeof(y));
            if(RightValue(n))
                exit(0);
            return;
        } else {
            vector<Point> p = player->optionCell(x - 1, y - 1, otherType, 1);
            player->updateVector(p, otherType);
            player->updateSpecificCell(x, y, otherType);
            screen.printPointOther(otherType,x,y);
            //cout << otherType << " played: (" << x << "," << y << ")" << endl;
        }
    }
    int xVal, yVal;
    if(board.fullBoard()) {
        if (board.getCountero() > board.getCounterx() ) {
            if (type == 'O')
                screen.printString("\nO You are the winner!\n");
                //cout << endl << "O You are the winner!" << endl;
            else
                screen.printString("\nyou are the loser, O the winner!\n");

            //cout << endl << "you are the loser, O the winner!" << endl;
        }else{
            if (type == 'X')
                screen.printString("\nX You are the winner!\n");

                //cout << endl << "X You are the winner!" << endl;
            else
                screen.printString("\nyou are the loser, X the winner!\n");

            //cout << endl << "you are the loser, X the winner!" << endl;
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
    if(RightValue(n))
        exit(0);
}

Point Client:: playOneTurnClient(char type) {
    board.printBoard();
    screen.printStringWithParameterBefore(type,": Its your move.\n");
    //cout << type << ": Its your move." << endl;
    vector<Point> op;
    screen.printString("Your possible moves: ");
    //cout<<"Your possible moves: ";
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
            screen.printString("\nPlease enter your move- row col: (e.g. 3 4) ");
            //cout << endl << "Please enter your move- row col: (e.g. 3 4) ";
            cin >> numX >> numY;
            screen.printEnter();
            //cout<<endl;
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
                screen.printString("Try Again!\n");
                //cout<<"Try again!"<<endl;
        } while(flag==0);
    }else{
        screen.printString("there is no move for you this turn.\n");
        //cout<<"there is no move for you this turn."<<endl;
        return Point(-2,-2);
    }
}

int Client::RightValue(int n){
    if (n == -1) {
        throw "Error writing arg to socket";
    } else if(n ==0){
        screen.printString("the server was closed.");
        close(clientSocket);
        return 1;
    }
    return 0;
}
