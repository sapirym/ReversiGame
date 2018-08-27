
#include <gtest/gtest.h>
#include "../src/Board.h"
#include "../src/HumanLogic.h"

/**
 * check the update vector - check if the right cell
 * was changed with the right value.
 */
TEST(HumanTest, updateVectorTest) {
    Board* b = new Board(4);
    HumanLogic h(*b);
    vector<Point> vector1;
    Point p(0,1);
    vector1.push_back(p);
    h.updateVector(vector1,'O');
    EXPECT_EQ((*b).getCell(0,1)->isO(),1);
}

/**
 * we check optionCell, we compare between the point
 * we need to change and the return answer from the
 * function.
 */
TEST(HumanTest, optionCellTest1) {
    Board* b = new Board(4);
    HumanLogic h(*b);
    vector<Point> v = h.optionCell(1,0,'X',0);
    EXPECT_EQ(v[0].getX(),1);
    EXPECT_EQ(v[0].getY(),1);
}

/**
 * we check optionCell with more difficult board.
 *compare between the point we need to change and
 * the return answer from the function.
 */
TEST(HumanTest, optionCellTest2) {
    Board* b = new Board(4);
    HumanLogic h(*b);
    (*b).updateCell(1,1,'O');
    (*b).updateCell(1,2,'X');
    (*b).updateCell(2,1,'X');
    (*b).updateCell(2,2,'X');
    vector<Point> v = h.optionCell(2,0,'O',0);
    EXPECT_EQ(v.size(),2);
}