
#include "animals.hpp"
#include "gtest/gtest.h"  // include the gtest functions & macros

TEST(AnimalTest, initMammal)
{
    Mammal groundhog(4);
    ASSERT_EQ(4, groundhog.get_num_of_feet());
}

TEST(AnimalTest, initSpider)
{
    Spider tarantula;
    ASSERT_EQ(8, tarantula.get_num_of_feet());
}
