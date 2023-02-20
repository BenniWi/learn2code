#include <stdio.h>

int main(void)
{
    // always use 5 grades
    unsigned int grades[] = {1, 2, 4, 1, 3};
    unsigned int sum_of_grades = 0;

    sum_of_grades += grades[0] + grades[1] + grades[2] + grades[3] + grades[4];

    printf("Average: %.1f\n", (double)sum_of_grades / 5.0f);
}
