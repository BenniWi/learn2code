#include <stdio.h>

#define NUMBER_OF_EXAMS (5U)
#define NAME_LENGTH (25U)

typedef struct
{
    unsigned int id;
    char name[NAME_LENGTH];
    float grades[NUMBER_OF_EXAMS];
} student;

int main(void)
{
    student max = {1234, "Max Mustermann", {1.2, 4.3, 1.4}};

    printf("=====================\n");
    // print the name in a colored output
    // you can find a lot of details here: https://stackoverflow.com/a/33206814
    // \033[ to start ANSI escape
    // 4 is underlined, 35 is magenta, 0 deletes all formats to return to default
    printf("\033[4;35m%s\033[0m\n", max.name);
    printf("ID: %u\n", max.id);
    printf("=====================\n");
    printf(" Grades: \n");
    // print all grades in a foor loop
    for (size_t i = 0; i < NUMBER_OF_EXAMS; ++i)
    {
        // we assume, that the array was initialized with zeros
        if (max.grades[i] > 0)
        {
            if (max.grades[i] >= 4.0)
            {
                // format: 31 is red, 0 set to default
                printf("  \033[1;31m%.1lf\033[0m\n", max.grades[i]);
            }
            else
            {
                printf("  %.1lf\n", max.grades[i]);
            }
        }
        else
        {
            break;
        }
    }
}
