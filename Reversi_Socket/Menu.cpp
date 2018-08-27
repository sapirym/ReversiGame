/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/


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
    cout << "Choose an opponent type:"<<endl
         <<"1. a human local player"<<endl
         <<"2. an AI player"<<endl
         <<"3. a remote player"<<endl;
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
                    cout<<"The file is empty.";
                file>>ip;
                file>>port;
                Client client(ip, port,board);
                try{
                    client.connectToServer();
                }catch (const char *msg){
                    cout<<"Failed to connect to server. reason: "<<msg<<endl;
                    exit(-1);
                }
                client.startGame();
                exit(-1);
            }
            default: {
                cout << "Try again!" << endl;
            }
        }
    }while (flag==0);
}