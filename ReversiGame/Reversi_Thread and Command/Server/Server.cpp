
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2
enum MassegeForServer{continueGame, noMove, endGame};
//void getCommand(string inputUser);


Server::Server(int port): port(port), serverSocket(0){
    cout<<"Server"<<endl;
    commandsManager=new CommandsManager();
}

/*void Server:: start(){
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket==-1){
        throw "Error opening socket.";
    }
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,sizeof(serverAddress));
    serverAddress.sin_family= AF_INET;
    serverAddress.sin_addr.s_addr= INADDR_ANY;
    serverAddress.sin_port=htons(port);
    if(bind(serverSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // StartCommand listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    int clientSocket, clientSocket2;
    //1 = end, 2 = noMove 0- continue.
    int massegeFlag = 0, changeClient = 0, firstClient = 0, firstTurn = 0;
    while (true) {
        firstTurn =0;
        firstClient = 0;
        massegeFlag=0;
        cout << "Waiting for client connections..." << endl;
        //while less then 2 player connect
        while (firstClient<2) {
            int msg0=0,msg1 = 1,msg2=2;
            //first player connect
            if(firstClient == 0){
                clientSocket = accept(serverSocket,(struct sockaddr *)&clientAddress,
                                      &clientAddressLen);
                if(clientSocket ==-1){
                    throw "Error on accept.";
                } else{
                    write(clientSocket,&msg0 ,sizeof(msg0));
                    cout<<"client 1 connected."<<endl;
                }
                //second player connect
            } else if(firstClient == 1){
                clientSocket2 = accept(serverSocket,(struct sockaddr *)&clientAddress,
                                       &clientAddressLen);

                if(clientSocket2 ==-1){
                    throw "Error on accept.";
                } else{
                    write(clientSocket2,&msg2 ,sizeof(msg2));
                    cout<<"client 2 connected."<<endl;
                }
            } else{
                break;
            }
            //counter of number of clients
            firstClient++;
        }

        int msg0=0,msg1 = 1, msg2=2,temp;
        //msg to the client of their type player game
        write(clientSocket,&msg1 ,sizeof(msg1));
        write(clientSocket2,&msg2 ,sizeof(msg2));
        //msg who is the player begin

        while (massegeFlag !=2 && clientSocket>0 && clientSocket2>0) {
            //swap between the players
            temp=clientSocket2;
            clientSocket2=changePlayer(clientSocket2, clientSocket, clientSocket2);
            clientSocket=temp;
            //the game move
            try {
                massegeFlag = handleClient(clientSocket2, firstTurn);
            } catch(const char* msg) {
                string s = "Client Disconnected";
                if(s.compare(msg)==0){
                 massegeFlag=2;
                } else{
                    throw msg;
                }
            }
            switch (massegeFlag) {
                case continueGame: {
                    firstTurn=1;
                    continue;
                }
                case noMove: {
                    firstTurn=1;
                    continue;
                }
                case endGame: {
                    massegeFlag =2;
                    break;
                }
            }
        }
        //close the clients after the game finish
        close(clientSocket);
        close(clientSocket2);
    }
}

int Server::changePlayer(int clientSocket, int clientOther, int currentClient){
    if(clientSocket==currentClient){
        return clientOther;
    } else{
        return clientSocket;
    }
}


*/

/*int Server:: handleClient(int clientSocket, int firstTurn){
    int n;
    if(firstTurn!=0) {
        n = write(clientSocket, &xPoint, sizeof(xPoint));
        if (n == -1) {
            throw "Error writing x.";
        } else if(n==0){
            throw "Client Disconnected";
        } try {
            n = write(clientSocket, &yPoint, sizeof(yPoint));
            if (n == -1) {
                throw "Error writing y.";
            } else if (n == 0) {
                throw "Client Disconnected";
            }
        } catch (exception e){
            if (n == -1) {
                throw "Error writing y.";
            } else if (n == 0) {
                throw "Client Disconnected";
            }
        }
    }
    // client move.
    n = read(clientSocket,&xPoint,sizeof(xPoint));
    if(n==-1){
        throw "Error reading x.";
    } else if(n==0) {
        throw "Client Disconnected";
    }
    n = read(clientSocket,&yPoint,sizeof(yPoint));
    if(n==-1){
        throw "Error reading y.";
    } else if(n==0) {
        throw "Client Disconnected";
    }
    //NoMove
    if((xPoint == -2 )&&(yPoint==-2)){
        return 1;
        //endGame
    } else if ((xPoint == -3 )&&(yPoint==-3)){
        return 2;
        //continue
    } else{
        return 0;
    }
}*/

void Server:: *handleClient(void * args){
    int n;
    int * clientSocket = (int*)args;
    string inputUser;
    n = read(*clientSocket,&inputUser,sizeof(inputUser));
    //do we need to allocate place?
    if(n==-1){
        throw "Error reading command.";
    } else if(n==0) {
        throw "Client Disconnected";
    }
    getCommand(inputUser);
}

void Server::run(){
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket==-1){
        throw "Error opening socket.";
    }
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,sizeof(serverAddress));
    serverAddress.sin_family= AF_INET;
    serverAddress.sin_addr.s_addr= INADDR_ANY;
    serverAddress.sin_port=htons(port);
    if(bind(serverSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // StartCommand listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    int clientSocket, clientSocket2;
    pthread_t thread;
    int n;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket,
                                   (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        n = pthread_create(&thread, NULL, handleClient, (void *)clientSocket);
        if(n==0){
            throw "Error on create thread";
        }

        // Close communication with the client
        //close(clientSocket);
    }
}
/*
void Server::listGame(int clientSocket){
    vector<string> clientList;
    map<string, int>::const_iterator it;
    for(it = gamesNames.begin(); it!=gamesNames.end();it++){
        if ((*it).second==1){
            clientList.push_back((*it).first);
        }
    }
    write(clientSocket,&clientList ,sizeof(clientList));
}
*/



void Server::getCommand(string inputUser){
    string command, firstInput, secondInput;
    command = inputUser.substr(0, inputUser.find("<"));
    if(inputUser.find("<")!=string::npos)
        firstInput= inputUser.substr(inputUser.find("<")+1,inputUser.find(">")-inputUser.find("<")+1);
    if(inputUser.find("><")!=string::npos)
        secondInput = firstInput.substr(inputUser.find(">")+2,inputUser.size()-3-inputUser.find(">"));
    vector<string> argsString;
    argsString.push_back(firstInput);
    argsString.push_back(secondInput);
    //CommandsManager commandsManager();
    commandsManager->executeCommand(command, argsString,games);
    /*   cout<<"inputUser:"<<inputUser<<endl;
            cout<<"command:"<<command<<endl;
    cout<<"firstInput:"<<firstInput<<endl;
    cout<<"second:"<<secondInput<<endl;*/
    //commandMap.find(command);
}