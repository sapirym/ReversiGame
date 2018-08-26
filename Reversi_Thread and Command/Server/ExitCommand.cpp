

#include "Command.h"
#include<iostream>
#include <unistd.h>

class ExitCommand : public Command {
public:
    pthread_mutex_t endMutex;
    virtual void execute(vector<string> args,vector<GameRoom> *games, int client) {
        if(!(*games).empty()){
            vector<GameRoom>::iterator it;
            int extMsg = -1;
            for (it = (*games).begin();it!=(*games).end(); it++){
                pthread_mutex_lock(&endMutex);
                write((*it).getFirstClient(), &extMsg, sizeof(extMsg));
                if((*it).getStatus()) {
                    write((*it).getSecondClient(), &extMsg, sizeof(extMsg));
                    close((*it).getSecondClient());
                }
                close((*it).getFirstClient());
                (*games).erase(it);
                pthread_mutex_unlock(&endMutex);
                break;
            }
        }
    }
};