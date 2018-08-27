//
// Created by sapir on 22/12/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H

#include<vector>
//#include <string>
#include "GameRoom.h"

using namespace std;

class Command {
public:
    virtual void execute(vector<string>* args,vector<GameRoom> games, int client) =0;
    virtual ~Command(){}
};


#endif //SERVER_COMMAND_H
