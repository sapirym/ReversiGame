
#include "Board.h"
#include <iostream>

Board::Board(int sizeOfBoard){
    size=sizeOfBoard;
    arr.resize(sizeOfBoard);
    arr = vector< vector<Cell*> >(size, vector<Cell*> (size));
    for (int k = 0; k < size; k++) {
        arr[k].resize(size);
        //arr[k] = vector<Cell*>(size);
    }
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            arr[i][j]= new Cell((i+1),(j+1));
    updateCell(size/2,size/2,'O');
    updateCell(size/2+1,size/2+1,'O');
    updateCell(size/2,size/2+1,'X');
    updateCell(size/2+1,size/2,'X');
}

Board::~Board() {
    for(int i=0;i<size;i++) {
        for (int j = 0; j < size; j++) {
            delete arr[i][j];
        }
    }
}

void Board::printBoard() {
    for(int n=0; n<size; n++){
        cout <<" | "<<n+1;
    }
    cout << " |";
    cout<< endl;
    cout<<string(((size)*4)+2, '-')<<endl;
    for(int i=0; i<size; i++) {
        cout << i+1<<"|";
        for(int j=0; j<size; j++) {
            if ((*arr[i][j]).getVal()=='X' || (*arr[i][j]).getVal()=='O'){
                cout<<" "<< (*arr[i][j]).getVal()<<" |";
            } else {
                cout << "   |";
            }
        }
        cout<<endl;
        cout<<string(size*4+2, '-')<<endl;
    }
    cout<<endl;
}
bool Board::fullBoard(){
    if(getCounterx()+getCountero()==(size*size))
        return 1;
    else
        return 0;
}
Cell* Board::getCell(int row,int col){
    return arr[row][col];
}
void Board::updateCell(int row,int col,char val) {
    if ((*arr[row-1][col-1]).isClear()) {
        (*arr[row - 1][col - 1]).setVal(val);
    } else {
        (*arr[row - 1][col - 1]).changeVal();

    }
}

void Board::updateCell2(int row,int col,char val) {
    if ((*arr[row][col]).isClear()) {
        (*arr[row][col]).setVal(val);
    } else {
        (*arr[row][col]).changeVal();
    }
}
void::Board::updateCell(int row,int col){
    (*arr[row - 1][col - 1]).restartCell();

}
Board::Board() {}
int Board::getCounterx() {
    int counter=0;
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size; ++j) {
            if((*getCell(i,j)).getVal()=='X')
                counter++;

        }
    }
    return counter;
}
int Board::getCountero() {
    int counter=0;
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size; ++j) {
            if((*getCell(i,j)).getVal()=='O')
                counter++;
        }
    }
    return counter;
}
int Board::getSize(){
    return size;
}
bool Board::onTheBoard(int row, int col){
    if(row<0||row>=size||col<0||col>=size)
        return 0;
    else
        return 1;
}
