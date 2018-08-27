//
// Created by sapir on 23/12/17.
//

#include "Command.h"
#include<iostream>
#include <unistd.h>

class StartCommand : public Command {
public:

    virtual void execute(vector<string> args,vector<GameRoom> *games, int client) {
        int msg;
        pthread_mutex_t startMutex;
        if(!(*games).empty()){
            vector<GameRoom>::iterator it;
            for (it = (*games).begin();it!=(*games).end(); it++) {
                if ((*it).getGameName().compare(args[0]) == 0) {
                    msg = -1;
                    write(client, &msg, sizeof(msg));

                }
            }
            msg = 1;
            pthread_mutex_lock(&startMutex);
            (*games).push_back(GameRoom(args[0], client, 0));
            pthread_mutex_unlock(&startMutex);
            write(client,&msg, sizeof(msg));
        }
    }
};