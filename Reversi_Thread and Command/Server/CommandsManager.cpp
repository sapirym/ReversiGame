

#include "CommandsManager.h"
#include "PrintCommand.cpp"
#include "JoinCommand.cpp"
#include "StartCommand.cpp"
#include "PlayCommand.cpp"
#include "CloseCommand.cpp"
#include "ExitCommand.cpp"
#include "ListGamesCommand.cpp"
#include "Command.h"


CommandsManager::CommandsManager(){
    commandsMap["print"] = new PrintCommand();
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"]= new ListGamesCommand(); //class of send to client
    commandsMap["join"]=new JoinCommand();
    commandsMap["play"]=new PlayCommand();
    commandsMap["close"]= new CloseCommand();
    commandsMap["exit"]= new ExitCommand();
}


void CommandsManager::executeCommand(string command, vector<string> args, vector<GameRoom> games) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args,games);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}