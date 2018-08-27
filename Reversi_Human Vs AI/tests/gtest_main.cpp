
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace testing;
/**
 * run all the tests.
 * @param argc
 * @param argv
 * @return itn value
 */
int main(int argc, char *argv[]) {
    InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

//DELETE MAIN.CPP FROM THE ORIGINAL PROJECT