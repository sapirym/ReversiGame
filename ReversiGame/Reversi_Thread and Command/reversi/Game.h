
#ifndef EX3ADVENCED_GAME_H
#define EX3ADVENCED_GAME_H

#include <string>
using namespace std;

#include "Board.h"
#include "Player.h"
#include "HumanLogic.h"
#include "ScreenView.h"

class Game {
public:
    /**
     * Board constructor.
     * @param board
     */
    Game(Board &board1);
    /**
     * THe metood run the game and check if the play is over.
     */
    void run();
    /**
     * initialize the Game with the appropriate logic.
     */
    void initializeGame(int choice);
    ~Game();
private:
    Board board;
    Player xPlayer;
    Player oPlayer;
    LogicBase * logicPlayer1;
    LogicBase * logicPlayer2;
    ScreenView screen;

};


#endif //EX3ADVENCED_GAME_H
