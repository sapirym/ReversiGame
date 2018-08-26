//
// Created by sapir on 22/12/17.
//
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include "Command.h"
#include "GameRoom.h"


using namespace std;
#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector<string> args, vector<GameRoom> games);
private:
    map<string, Command *> commandsMap;
};


#endif //SERVER_COMMANDSMANAGER_H
