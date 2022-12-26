
#include "gtest/gtest.h" // include the gtest functions & macros
extern "C" { //the library we want to us is written in C
  #include "functions.h"
}

// the first test we want to write
TEST (example8_tests, add_standard_integers) { 

    EXPECT_EQ (11, add_integers(5,6));
}

TEST (example8_tests, add_zeros) { 
    EXPECT_EQ (0, add_integers(0,0));
}

#if 0
TEST (example8_tests, overflow) { 
    EXPECT_EQ (2147483648, add_integers(2147483647,1));
}
#endif