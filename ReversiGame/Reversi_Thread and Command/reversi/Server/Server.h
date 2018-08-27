//
// Created by sapir on 27/11/17.
//

#ifndef EX3ADVENCED_SERVER_H
#define EX3ADVENCED_SERVER_H


#include "../Point.h"
#include "../Board.h"
#include "../HumanLogic.h"

class Server {
public:
    Server(int port);//, Board &board);
    void start();
    // void stop();
private:
    int port;
    int serverSocket;
    int xPoint, yPoint;
    char type;
    // the socket's file descriptor
    int handleClient(int clientSocket, int firstTurn);
    int changePlayer(int clientSocket, int clientOther, int currentClient);
    //int playOneTurn(int arg1,const char op, int arg2) const;
};


#endif //EX3ADVENCED_SERVER_H
