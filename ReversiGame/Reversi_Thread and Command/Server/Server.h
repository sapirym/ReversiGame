//
// Created by sapir on 03/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "CommandsManager.h"
#include "GameRoom.h"


using namespace std;

class Server {
public:
    /**
     * constructor.
     * @param port
     */
    Server(int port);
    /**
     * run the server.
     */
    //void start();
    void getCommand(string inputUser);
    //void createCommandMap(string inputUser);
    //void listGame(int clientSocket);
    //void joinGame(int clientSocket, string name);
    void run();
    void  *handleClient(void * args);
private:
    int port;
    int serverSocket;
    int xPoint, yPoint;
    //template <typename T>;
    //std::map<string, T> commandMap;
    std::map<string, int> map_type;
    std::map<string, int> gamesNames;


    /**
     * move the point from one client to the other
     * @param clientSocket
     * @param firstTurn
     * @return
     */
    //int handleClient(int clientSocket, int firstTurn);
    /**
     * replace between the clients
     * @param clientSocket
     * @param clientOther
     * @param currentClient
     * @return the serverSocket
     */
    int changePlayer(int clientSocket, int clientOther, int currentClient);
    CommandsManager *commandsManager;
    vector<GameRoom> games;

};




#endif //SERVER_SERVER_H
