//
// Created by sapir on 25/12/17.
//

#include <iostream>
#include "SecondMenu.h"

SecondMenu::SecondMenu(){}

string SecondMenu::getChoice(){
    string gameName;
    int choice;
    screen.printSecondMenu();
    do{
        cin>>choice;
        string returnStr;
        if(choice==1|| choice==2){
            screen.printString("choose the name of the game:\n");
            cin>>gameName;
            if(choice==1) {
                returnStr = "start<" + gameName + ">";
                returnStr.append("\0");
                return returnStr;
            }
            else {
                returnStr =  "join<" + gameName + ">";
                returnStr.append("\0");
                return returnStr;
            }
        }
        else if(choice==3){
            returnStr = "list_games";
            returnStr.append("\0");
            return returnStr;
        }
        if(choice!=1&&choice!=2&&choice!=3){
            screen.printString("Try again!\n");
        }
    }while (choice!=1&&choice!=2&&choice!=3);
}
