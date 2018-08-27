//
// Created by hadas on 04/12/17.
//

#ifndef EX3ADVENCED_GAMEFLOWBASE_H
#define EX3ADVENCED_GAMEFLOWBASE_H

#include "LogicBase.h"
#include "Board.h"

using namespace std;

class GameFlowBase {
public:
    /**
     * constructor.
     * @param b Board
     */
    //GameFlow(Board &b, LogicBase* playerLogic1, LogicBase *playerLogic2);
    /**
     * The method runs the game every time each player separately
     * @param type - 'X'or 'O'
     * @return 1 if the player do move, 0- if he stack
     */
    virtual Point playOneTurn(char type)=0;
private:

    LogicBase *playerRule1;
    LogicBase *playerRule2;
    Board board;
};



#endif //EX3ADVENCED_GAMEFLOWBASE_H
