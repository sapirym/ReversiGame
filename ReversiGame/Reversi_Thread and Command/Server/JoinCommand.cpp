//
// Created by sapir on 23/12/17.
//

#include "Command.h"
#include "Server.h"
#include<iostream>
#include <map>
#include <unistd.h>

class JoinCommand : public Command {
public:
    pthread_mutex_t closeMutex;
    virtual void execute(vector<string> args,vector<GameRoom> *games, int client) {
        int msg =1;
        int msg2 =2;
        int firstClient = 0;
        if(!(*games).empty()){
            vector<GameRoom>::iterator it;
            for (it = (*games).begin();it!=(*games).end(); it++){
                if((*it).getGameName().compare(args[0])==0){
                    if((*it).getStatus()==0){
                        pthread_mutex_lock(&closeMutex);
                        (*it).setStatus();
                        (*it).setSecondClient(client);
                        firstClient = (*it).getFirstClient();
                        write(firstClient, &msg, sizeof(msg));
                        write(client, &msg2, sizeof(msg2));
                        pthread_mutex_unlock(&closeMutex);
                        break;
                    }
                }
            }
            msg = -1;
            write(firstClient,&msg, sizeof(msg));
        }
    }

};