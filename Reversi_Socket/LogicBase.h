/**
 * hadas berger: 316590215
 * sapir yamin: 316251818
 **/
#include <iostream>
#include <vector>
#include "Point.h"

#ifndef EX3ADVENCED_LOGICBASE_H
#define EX3ADVENCED_LOGICBASE_H
using namespace std;

//interface of the player

class LogicBase {
public:

    virtual void updateVector(vector<Point> p,char type)  = 0;
    virtual vector<Point> optionCell(int i,int j,char type,int print) = 0;
    virtual int playMove(char type,  vector<Point> op)   =0;
};
#endif //EX3ADVENCED_LOGICBASE_H
