

#ifndef EX3ADVENCED_BOARD_H
#define EX3ADVENCED_BOARD_H

#include <string>
#include <vector>

using namespace std;


#include "Cell.h"
class Board {
public:
    Board(int size);
    Board(const Board& board);
    Board();
    ~Board();
    vector< vector<Cell*> >  getArr();
    /**
     * the metood print the board
     */
    void printBoard();
    /**
     * the metood check if the bosrd is full
     * @return 1-if the board is full 0-otherwise
     */
    bool fullBoard();
    /**
     * @param row
     * @param col
     * @return the cell we call
     */
    Cell* getCell(int row,int col);
    /**
     * update the Cell
     * @param row
     * @param col
     * @param val
     */
    void updateCell(int row,int col, char val);
    void updateCell2(int row,int col, char val);
    /**
     * update the Cell
     * @param row
     * @param col
     */
    void updateCell(int row,int col);
    int getCounterx();
    int getCountero();
    /**
     *
     * @return the board size
     */
    int getSize();
    /**
     * check if the input is in the board limit
     * @param row
     * @param col
     * @return
     */
    bool onTheBoard(int row, int col);


private:
    int size;
    vector< vector<Cell*> >  arr;
};

#endif //EX3ADVENCED_BOARD_H
