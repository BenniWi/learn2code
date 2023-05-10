#include "student.h"

int main(void)
{
    student max, maria;

    student_init(&max, "Max Mustermann");
    student_add_grade(&max, 1.2f);
    student_add_grade(&max, 4.3f);
    student_add_grade(&max, 1.4f);

    student_init(&maria, "Maria Musterfrau");
    student_add_grade(&maria, 5.0f);
    student_add_grade(&maria, 1.0f);

    student_print(&max);
    student_print(&maria);

    return 0;
}
