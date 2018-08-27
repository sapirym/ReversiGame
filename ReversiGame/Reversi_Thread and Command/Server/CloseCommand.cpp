//
// Created by sapir on 23/12/17.
//


#include "Command.h"
#include<iostream>
#include <unistd.h>

class CloseCommand : public Command {
public:
    pthread_mutex_t closeMutex;
    virtual void execute(vector<string> args,vector<GameRoom> *games, int client) {
        if(!(*games).empty()){
            vector<GameRoom>::iterator it;
            for (it = (*games).begin();it!=(*games).end(); it++){
                if((*it).getGameName().compare(args[0])==0){
                    if((*it).getFirstClient()==client
                       ||(*it).getSecondClient()==client){
                        pthread_mutex_lock(&closeMutex);
                        close((*it).getFirstClient());
                        close((*it).getSecondClient());
                        (*games).erase(it);
                        pthread_mutex_unlock(&closeMutex);
                        break;
                    }
                }
            }
        }
    }
};