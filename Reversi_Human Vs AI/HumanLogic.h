

#ifndef EX3ADVENCED_LOGIC_H
#define EX3ADVENCED_LOGIC_H


#include "Cell.h"
#include "Board.h"
#include "Point.h"
#include "LogicBase.h"

#include <vector>

class HumanLogic: public LogicBase{
public:
    /**
     * constructor.
     * @param b
     */
    HumanLogic(Board &b);
    HumanLogic();
    /**
     * play the human move.
     * @param type - 'x' or 'o'
     * @param op the vector to update
     * @return 1-if the player doesnt do any move. 0-otherwise
     */
    int playMove(char type, vector<Point> op);
    /**
 * update the vector to the match value
 * @param p - the vector
 * @param type -the val to change to
 */
    void updateVector(vector<Point> p,char type);
    /**
     *  The method return the option cell to flip if the cell will chosen
     * @param i - x cell position
     * @param j - y cell position
     * @param type - the type to check on
     * @param print - if we need to print message
     * @return vector with the point to change if cell(i,j) will choose
     */
    vector<Point> optionCell(int i,int j,char type,int print);
private:
    Board board;
};


#endif //EX3ADVENCED_LOGIC_H
