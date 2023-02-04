#include "student.h"

#include <stdio.h>
#include <stdlib.h>

srand(time(NULL));   // Initialization, should only be called once.

void student_init(student *const s, const char name[NAME_LENGTH])
{
	int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
		unsigned int id;
	char name[NAME_LENGTH];
	float grades[NUMBER_OF_EXAMS];
	unsigned int num_of_grades;
}

void student_print(student const * const s)
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


bool student_add_grade(student * const s, float grade);
