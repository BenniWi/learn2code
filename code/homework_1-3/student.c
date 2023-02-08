#include <stdio.h>

#define NUMBER_OF_EXAMS (5U)
#define NAME_LENGTH (25U)

typedef struct
{
    unsigned id;
    char name[NAME_LENGTH];
    double grades[NUMBER_OF_EXAMS];
} student;

int main(void)
{
    student max = {1234, "Max Mustermann", {1.2, 4.3, 1.4}};

    printf("=====================\n");
    printf("%s", max.name);
    printf("ID: %u\n", max.id);
    printf("=====================\n");
}
