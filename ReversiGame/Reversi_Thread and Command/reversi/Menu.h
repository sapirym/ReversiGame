//
// Created by sapir on 27/11/17.
//

#ifndef EX3ADVENCED_MENU_H
#define EX3ADVENCED_MENU_H



#include "Board.h"
#include "LogicBase.h"
#include "Player.h"
#include "ScreenView.h"

class Menu {
public:
    /**
     * constructor.
     * @param b
     */
    Menu(Board& b);
    /**
     * tun the menu of the game.
     */
    void runMenu();
private:
    Board board;
    Player xPlayer;
    Player oPlayer;
    LogicBase * logicPlayer1;
    LogicBase * logicPlayer2;
    ScreenView screen;
};


#endif //EX3ADVENCED_MENU_H
