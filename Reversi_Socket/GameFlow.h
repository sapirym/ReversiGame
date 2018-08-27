/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#ifndef EX3ADVENCED_GAMEFLOW_H
#define EX3ADVENCED_GAMEFLOW_H
#include <string>
#include "HumanLogic.h"
#include "Board.h"
#include "ComputerLogic.h"
#include "GameFlowBase.h"

using namespace std;

class GameFlow: public GameFlowBase {
public:
    /**
     * constructor.
     * @param b Board
     */
    GameFlow(Board &b, LogicBase* playerLogic1, LogicBase *playerLogic2);
    /**
     * The method runs the game every time each player separately
     * @param type - 'X'or 'O'
     * @return 1 if the player do move, 0- if he stack
     */
    Point playOneTurn(char type);

private:

    LogicBase *playerRule1;
    LogicBase *playerRule2;
    Board board;
};



#endif //EX3ADVENCED_GAMEFLOW_H
