
#include "Cell.h"
#include <iostream>
Cell::Cell(int posRo,int posCo) {
    val=0;
}


Cell::Cell(){}
Cell::~Cell(){}


bool Cell::isX(){
    if (val=='X')
        return 1;
    else
        return 0;
}
bool Cell::isO(){
    if (val=='O')
        return 1;
    else
        return 0;
}
bool Cell::isClear(){
    if(val==0)
        return 1;
    else
        return 0;
}
void Cell::changeVal(){
    if((isClear())==0)
        if(isX())
            changeValToO();
        else
            changeValToX();
}
void Cell::changeValToX(){
    setVal('X');
}
void Cell::changeValToO(){
    setVal('O');
}

void Cell::setVal(char v) {
    val=v;
}
char Cell::getVal(){
    return val;
}

void Cell::restartCell(){
    setVal(0);
}