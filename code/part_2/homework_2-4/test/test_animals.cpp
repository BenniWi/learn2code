
#include "animals.hpp"
#include "gtest/gtest.h"  // include the gtest functions & macros

class AnimalTestFixture : public ::testing ::Test
{
   protected:
    Mammal squirrel_ = Mammal(4, 10.0);
    Spider black_widow_ = Spider(5.0);
};

TEST(AnimalTest, initMammal)
{
    Mammal groundhog = Mammal(4, 10.0);
    ASSERT_EQ(4, groundhog.get_num_of_feet());
}

TEST(AnimalTest, initSpider)
{
    Spider tarantula = Spider(2.0);
    ASSERT_EQ(8, tarantula.get_num_of_feet());
}

TEST_F(AnimalTestFixture, movelMammal)
{
    squirrel_.move(1.0);
    ASSERT_FLOAT_EQ(squirrel_.get_position(), 10.0);
    squirrel_.move(2.0);
    ASSERT_FLOAT_EQ(squirrel_.get_position(), 30.0);

    black_widow_.move(1.0);
    ASSERT_FLOAT_EQ(black_widow_.get_position(), 5.0);
    black_widow_.move(2.0);
    ASSERT_FLOAT_EQ(black_widow_.get_position(), 15.0);
}