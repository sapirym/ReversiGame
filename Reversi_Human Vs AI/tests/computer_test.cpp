

#include <gtest/gtest.h>
#include "../src/Board.h"
#include "../src/ComputerLogic.h"

/**
 * check the demo move - we push 3 points that
 * we know that one of them is the correct,
 * then, we compare between the right result and the return
 * value of the function.
 */
TEST(ComputerLogicTest, demoMoveTest) {
    Board* b = new Board(4);
    ComputerLogic computerLogic(*b);
    (*b).updateCell(2,2);
    (*b).updateCell(2,3);
    vector<Point> v;
    v.push_back(Point(1,3));
    v.push_back(Point(3,1));
    v.push_back(Point(3,3));
    Point finalMove =computerLogic.demoMove(v);
    EXPECT_EQ(finalMove.getX(),1);
    EXPECT_EQ(finalMove.getY(),3);
}

/**
 * we check the cleanVec function - we change
 * the board, then we clean the borad and check
 * if it was cleaned
 */
TEST(ComputerLogicTest, cleanVectorTest) {
    Board* b = new Board(4);
    ComputerLogic computerLogic(*b);
    vector<Point> vector1;
    Point p(0,1);
    vector1.push_back(p);
    computerLogic.cleanVector(vector1,'O');
    EXPECT_EQ((*b).getCell(0,1)->isX(),1);
}

/**
 * we check playMove function - we making a vector
 * of points, then we send it to the function and
 * check if the result is 0 - that's means that the
 * return value is correct.
 */
TEST(ComputerLogicTest, playMoveTest) {
    Board* b = new Board(4);
    ComputerLogic computerLogic(*b);
    vector<Point> v;
    v.push_back(Point(0,0));
    v.push_back(Point(0,2));
    v.push_back(Point(2,0));
    int answer = computerLogic.playMove('O',v);
    EXPECT_EQ(answer,0);
}