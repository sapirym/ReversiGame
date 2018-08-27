

#include <gtest/gtest.h>
#include "../include/factorial.h"
#include "../src/Board.h"
#include "../src/Point.h"

/**
 * check outofBoard - check if the function reconized
 * if the point is out of the limit.
 */
TEST(boardTest,outOfBound){
    Board b1(8);
    EXPECT_EQ(b1.onTheBoard(-1,-1),0);
    EXPECT_EQ(b1.onTheBoard(0,-1),0);
    EXPECT_EQ(b1.onTheBoard(-1,0),0);
    EXPECT_EQ(b1.onTheBoard(5,4),1);
    EXPECT_EQ(b1.onTheBoard(9,8),0);
    Board b2(2);
    EXPECT_EQ(b2.onTheBoard(-1,-1),0);
}
/**
 * check if the board is full.
 */
TEST(boardTest,FullBoard) {
    Board b(2);
    EXPECT_EQ(b.fullBoard(),1);
    Board b1(4);
    EXPECT_EQ(b1.fullBoard(),0);

}

/**
 * check if the counter of o and x are correct.
 */
TEST(boardTest,counters) {
    Board b(4);
    b.updateCell2(1,0,'O');
    EXPECT_EQ(b.getCountero(),3);
    b.updateCell2(2,0,'O');
    b.updateCell2(3,0,'O');
    EXPECT_EQ(b.getCountero(),5);
    EXPECT_EQ(b.getCounterx(),2);
}

/**
 * check the type of the cell.
 */
TEST(boardTest,checkType) {
    Board b(4);
    EXPECT_TRUE(b.getCell(1,1)->isO());
    EXPECT_FALSE(b.getCell(1,1)->isX());
}