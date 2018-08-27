//
// Created by sapir on 25/12/17.
//

#ifndef EX3ADVENCED_SCREENVIEW_H
#define EX3ADVENCED_SCREENVIEW_H


#include "Board.h"

class ScreenView {
public:
    ScreenView();
    void printPoint(string s,int x,int y);
    void printError(string s,string msg);
        void printString(string s);
    void printBoard(Board&board);
    void printEnter();
        void printStringWithParameterParameterBefore(string s, char n);
    void printStringWithParameterBefore(char n,string s);
    void printPointOther(char s,int x,int y);
        void printStringWithMsgBefore(string s, char n);
    void printMove();
    void printMenu();
    void printSecondMenu();
};


#endif //EX3ADVENCED_SCREENVIEW_H
