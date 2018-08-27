
#ifndef EX3ADVENCED_CELL_H
#define EX3ADVENCED_CELL_H

#include <string>
using namespace std;

class Cell {
public:
    Cell(int posRo,int posCo);
    Cell();
    ~Cell();
    /**
     * @return 1-if val is -'x' 0-otherwise
     */
    bool isX();
    /**
     * @return 1-if val is -'o' 0-otherwise
     */
    bool isO();
    /**
     * @return 1-if val!=x or o 0-otherwise
     */
    bool isClear();
    /**
     * change val x to o and  thr opposite
     */
    void changeVal();
    /**
     * change val to x
     */
    void changeValToX();
    /**
     * change val to o
     */
    void changeValToO();
    //void printVal() const;
    /**
     * @return the val
     */
    char getVal();
    /**
     * set the val to the input
     * @param v
     */
    void setVal(char v);
    /**
     * change the value to 0
     */
    void restartCell();

private:
    char val;

};


#endif //EX3ADVENCED_CELL_H
