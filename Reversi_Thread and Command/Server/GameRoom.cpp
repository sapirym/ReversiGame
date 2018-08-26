

#include "GameRoom.h"
GameRoom::GameRoom(string gameName1, int firstClient1, int secondClient1){
    gameName=gameName1;
    status=0;
    firstClient=firstClient1;
    secondClient=secondClient1;
}
int GameRoom::getFirstClient(){
    return firstClient;
}
int GameRoom::getSecondClient(){
    return secondClient;
}
void GameRoom::setStatus(){
    status=1;
}
string GameRoom::getGameName(){
    return gameName;
}
void GameRoom::setSecondClient(int client){
    secondClient=client;
}
int GameRoom::getStatus(){
    return status;
}