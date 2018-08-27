


#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Menu.h"
#include "Game.h"
#include "Client.h"

Menu::Menu(Board &board1) {
    board = board1;
}
void Menu::runMenu(){
    int userChoose, flag = 0;
    Game gameBase(board);
    screen.printMenu();
    /*cout << "Choose an opponent type:"<<endl
         <<"1. a human local player"<<endl
         <<"2. an AI player"<<endl
         <<"3. a remote player"<<endl;*/
    do {
        cin >> userChoose;
        switch (userChoose) {
            case 1:
            case 2: {
                gameBase.initializeGame(userChoose);
                gameBase.run();
                flag=1;
            }
            case 3: {
                flag=1;
                int port;
                char* ip;
                ifstream file;
                file.open("clientConfiguration.txt");
                if(file==NULL)
                    screen.printString("The file is empty.\n");
                    //cout<<"The file is empty.";
                file>>ip;
                file>>port;
                Client client(ip, port,board);
                try{
                    client.connectToServer();
                }catch (const char *msg){
                    screen.printError("Failed to connect to server. reason: ",msg);
                    //cout<<"Failed to connect to server. reason: "<<msg<<endl;
                    exit(-1);
                }
                //client.startGame();
                exit(0);
            }
            default: {
                screen.printString("Try again!\n");
                //cout << "Try again!\n" << endl;
            }
        }
    }while (flag==0);
}