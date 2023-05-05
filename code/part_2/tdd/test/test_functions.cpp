
#include "functions.h"
#include "gtest/gtest.h"  // include the gtest functions & macros

// the first test we want to write
TEST(tdd_tests, AddStandardIntegers)
{
    EXPECT_EQ(11, add_integers(5, 6));
}

TEST(tdd_tests, AddZeros)
{
    EXPECT_EQ(0, add_integers(0, 0));
}

#if 0
TEST (tdd_tests, overflow) { 
    EXPECT_EQ (2147483648, add_integers(2147483647,1));
}
#endif
