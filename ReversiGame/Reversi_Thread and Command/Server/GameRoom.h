//
// Created by sapir on 23/12/17.
//

#ifndef SERVER_GAMEROOM_H
#define SERVER_GAMEROOM_H

#include <iostream>
using namespace std;

class GameRoom {
public:
    GameRoom(string gameName, int firstClient, int secondClient);
    int getFirstClient();
    int getSecondClient();
    void setStatus();
    string getGameName();
    void setSecondClient(int client);
    int getStatus();
private:
    string gameName;
    bool status;
    int firstClient;
    int secondClient;
};


#endif //SERVER_GAMEROOM_H
