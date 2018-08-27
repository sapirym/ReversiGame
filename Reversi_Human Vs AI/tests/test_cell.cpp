

#include <gtest/gtest.h>
#include "../src/Cell.h"

/**
 * check if the value of the cell was change by
 * the right value.
 */
TEST(CellTest,checkChnge) {
    Cell c(1,2);
    EXPECT_TRUE(c.isClear());
    c.changeValToO();
    EXPECT_FALSE(c.isX());
    Cell c1(0,0);
    EXPECT_TRUE(c1.isClear());

}