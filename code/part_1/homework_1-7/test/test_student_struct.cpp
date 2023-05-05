
#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "student.h"
}

class StudentTest : public ::testing ::Test
{
   protected:
    student max;
    void SetUp() override
    {
        // set some values to check if the init method overwrites them correctly
        max.id = 0;
        max.num_of_grades = 100;
        // init the student
        student_init(&max, "Max Mustermann");
    }
};

// the first test we want to write
TEST_F(StudentTest, init)
{
    ASSERT_STREQ("Max Mustermann", max.name);
    ASSERT_NE(0, max.id);
    ASSERT_EQ(0, max.num_of_grades);
    for (unsigned int i = 0; i < NUMBER_OF_EXAMS; ++i)
    {
        ASSERT_EQ(0, max.grades[i]);
    }
}

TEST_F(StudentTest, AddGrades)
{
    student_add_grade(&max, 1.0f);
    ASSERT_EQ(1, max.num_of_grades);
    student_add_grade(&max, 2.0f);
    ASSERT_EQ(2, max.num_of_grades);
    student_add_grade(&max, 3.0f);
    ASSERT_EQ(3, max.num_of_grades);
    student_add_grade(&max, 4.5f);
    ASSERT_EQ(4, max.num_of_grades);

    ASSERT_FLOAT_EQ(1.0f, max.grades[0]);
    ASSERT_FLOAT_EQ(2.0f, max.grades[1]);
    ASSERT_FLOAT_EQ(3.0f, max.grades[2]);
    ASSERT_FLOAT_EQ(4.5f, max.grades[3]);
}

TEST_F(StudentTest, AddGradesOverflow)
{
    student_add_grade(&max, 1.0f);
    student_add_grade(&max, 2.0f);
    student_add_grade(&max, 3.0f);
    student_add_grade(&max, 4.0f);
    student_add_grade(&max, 5.0f);
    student_add_grade(&max, 6.0f);
    ASSERT_EQ(5, max.num_of_grades);
}