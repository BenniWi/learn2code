#ifndef STUDENT_H_
#define STUDENT_H_

#define NUMBER_OF_EXAMS (5U)
#define NAME_LENGTH (25U)

typedef struct
{
    unsigned int id;
    char name[NAME_LENGTH];
    float grades[NUMBER_OF_EXAMS];
    unsigned int num_of_grades;
} student;

void student_init(student *const s, const char name[]);
void student_print(student const *const s);
void student_add_grade(student *const s, float grade);

#endif /* STUDENT_H_ */
