

#include <unistd.h>
#include "Command.h"
class ListGamesCommand : public Command {
public:
    pthread_mutex_t ListGamesMutex;
    virtual void execute(vector<string> args, vector<GameRoom>* games, int client) {
        vector<string>gamesNames;
        if(!games->empty()){
            for (int i=0;i<(*games).size(); i++){
                if((*games)[i].getStatus()==0){
                    pthread_mutex_lock(&ListGamesMutex);
                    gamesNames.push_back((*games)[i].getGameName());
                    pthread_mutex_unlock(&ListGamesMutex);
                }
            }
            pthread_mutex_lock(&ListGamesMutex);
            write(client, &gamesNames, sizeof(gamesNames));
            pthread_mutex_unlock(&ListGamesMutex);
        }
    }
};