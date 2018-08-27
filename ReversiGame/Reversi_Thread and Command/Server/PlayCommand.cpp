//
// Created by sapir on 23/12/17.
//


#include "Command.h"
#include<iostream>
#include <unistd.h>

class PlayCommand : public Command {
public:
    pthread_mutex_t playMutex;
    virtual void execute(vector<string> args,vector<GameRoom> *games, int client) {
        int currentClient=0;
        if(args.size() == 2){
            if(!(*games).empty()){
                vector<GameRoom>::iterator it;
                for (it = (*games).begin();it!=(*games).end(); it++){
                    if((*it).getFirstClient()==client){
                        pthread_mutex_lock(&playMutex);
                        currentClient=(*it).getSecondClient();
                        pthread_mutex_unlock(&playMutex);
                       if((*it).getSecondClient()==client ) {
                           pthread_mutex_lock(&playMutex);
                           currentClient = (*it).getFirstClient();
                           pthread_mutex_unlock(&playMutex);
                       }
                        if(currentClient!=0){
                            pthread_mutex_lock(&playMutex);
                            write(currentClient,&args[0], sizeof(args[0]));
                            write(currentClient,&args[1], sizeof(args[1]));
                            pthread_mutex_unlock(&playMutex);
                            break;
                        }
                    }
                }
            }
        }
    }
};