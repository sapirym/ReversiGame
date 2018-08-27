//
// Created by hadas on 04/12/17.
//

#ifndef EX3ADVENCED_GAMESOCKET_H
#define EX3ADVENCED_GAMESOCKET_H


#include "GameFlowBase.h"
#include "HumanLogic.h"

class GameSocket: GameFlowBase {
public:
    GameSocket(HumanLogic *player);
    Point playOneTurn(char type);
private:
    LogicBase *playerRule1;
    LogicBase *playerRule2;
    Board board;
    HumanLogic *player;

};


#endif //EX3ADVENCED_GAMESOCKET_H
