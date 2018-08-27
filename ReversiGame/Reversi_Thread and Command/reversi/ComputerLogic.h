
#include <vector>
#include <map>
#include "Cell.h"
#include "Point.h"
#include "Board.h"
#include "LogicBase.h"
#include "ScreenView.h"

#ifndef EX3ADVENCED_COMPUTERLOGIC_H
#define EX3ADVENCED_COMPUTERLOGIC_H


class ComputerLogic: public LogicBase {
public:
    /**
     * constructor.
     * @param b - board
     */
    ComputerLogic(Board &b);
    /**
     * After the demo function change's- return to the original board
     * @param p - the vector to change
     * @param type - change the vector to
     */
    void cleanVector(vector<Point> p,char type);
    /**
     *  The method return the option cell to flip if the cell will chosen
     * @param i - x cell position
     * @param j - y cell position
     * @param type - the type to check on
     * @return vector with the point to change if cell(i,j) will choose
     */
    vector<Point> optionCell(int i,int j,char type,int print);
    /**
     * The method check what is the ultimate place to thr computer to choose.
     * He run "demo move" for all the Options and check what is the best choise to the human.
     * Finally he choose the the move that will give him the maximum number of cells
     * and in contrast will make the human to a minimum of cells in his next move.
     * @param p - the computer options
     * @return the point for maximum computer move
     */
    Point demoMove(vector<Point> p);
    /**
    * update the vector to the match value
    * @param p - the vector
    * @param type -the val to change to
     */
    void updateVector(vector<Point> p,char type);
    /**
     * play the computer move.
     * @param type - 'x' or 'o'
     * @param op the vector to update
     * @return 1-if the player doesnt do any move. 0-otherwise
     */
    int playMove(char type,  vector<Point> op);
private:
    Board board;
    ScreenView screen;

};


#endif //EX3ADVENCED_COMPUTERLOGIC_H
