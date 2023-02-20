#include <stdio.h>
#include <stdlib.h>  // because we want to use the "exit" command

int main(void)
{
    unsigned int grades[] = {1, 2, 4, 1, 3};
    // calculate the size of the array automatically
    unsigned int number_of_grades = sizeof(grades) / sizeof(unsigned int);
    unsigned int sum_of_grades = 0;
    unsigned int i = 0;

    for (i = 0; i < number_of_grades; ++i)
    {
        if (grades[i] > 6)  // grades is unsigned int, so no check for <0 necessary
        {
            printf("Invalid grade %u, exiting\n", grades[i]);
            exit(-1);
        }
        sum_of_grades += grades[i];
    }

    if (number_of_grades > 0)
    {
        printf("Average: %.1f\n", (double)sum_of_grades / (double)number_of_grades);
    }
    else
    {
        printf("No grades entered\n");
    }
}
