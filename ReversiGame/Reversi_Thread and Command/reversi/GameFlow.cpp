/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/

#include <iostream>
#include <vector>
#include "GameFlow.h"


GameFlow::GameFlow(Board &b, LogicBase *playerLogic1, LogicBase* playerLogic2)  {
    board=b;
    playerRule1 = playerLogic1;
    playerRule2 = playerLogic2;
}

int GameFlow::playOneTurn(char type) {
    board.printBoard();
    //cout << type << ": Its your move." << endl;
    screen.printStringWithParameterParameterBefore(": Its your move.\n", type);
    vector<Point> op;
    //cout<<"Your possible moves: ";
    screen.printString("Your possible moves: ");
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            //send a clean cell and check is option
            if (board.getCell(i , j )->isClear()) {
                if(type == 'X') {
                    vector<Point> p = playerRule1->optionCell(i, j, type,0);
                    if (!p.empty()) {
                        //print the option
                        op.push_back(Point(i, j));
                    }
                } else{
                    vector<Point> p = playerRule2->optionCell(i,j,type,0);
                    if(!p.empty()){
                        op.push_back(Point(i,j));
                    }
                }
            }
        }
    }
    if(type == 'O'){
        return playerRule2->playMove(type, op);
    }else
        return playerRule1->playMove(type,op);
}