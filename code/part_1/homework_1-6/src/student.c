#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_init(student *const s, const char name[])
{
    s->id = rand();  // Returns a pseudo-random integer between 0 and RAND_MAX.
    // instead of using a for loop to copy the array, we can use strncpy
    strncpy(s->name, name, strlen(name) + 1);
    for (unsigned int i = 0; i < NUMBER_OF_EXAMS; ++i)
    {
        s->grades[i] = 0.0f;
    }
    s->num_of_grades = 0;
}

void student_print(student const *const s)
{
    if (s == NULL)
    {
        printf("Invalid data\n");
    }
    else
    {
        printf("=====================\n");
        // print the name in a colored output
        // you can find a lot of details here: https://stackoverflow.com/a/33206814
        // \033[ to start ANSI escape
        // 4 is underlined, 35 is magenta, 0 deletes all formats to return to default
        printf("\033[4;35m%s\033[0m\n", s->name);
        printf("ID: %u\n", s->id);
        printf("=====================\n");
        printf(" Grades: \n");
        // print all grades in a foor loop
        // we determine the size of the array with the sizeof function
        for (unsigned int i = 0; i < s->num_of_grades; ++i)
        {
            // we assume, that the array was initialized with zeros
            if (s->grades[i] > 0)
            {
                if (s->grades[i] >= 4.0f)
                {
                    // format: 31 is red, 0 set to default
                    printf("  \033[1;31m%.1lf\033[0m\n", s->grades[i]);
                }
                else
                {
                    printf("  %.1lf\n", s->grades[i]);
                }
            }
            else
            {
                break;
            }
        }
    }
}

void student_add_grade(student *const s, float grade)
{
    if (s->num_of_grades < NUMBER_OF_EXAMS)
    {
        s->grades[s->num_of_grades] = grade;
        ++(s->num_of_grades);
    }
    else
    {
        printf("!!! Can not add more grades to student %s. Maximum number of grades is %i\n", s->name, NUMBER_OF_EXAMS);
    }
}
