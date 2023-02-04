#include "student.h"

#include <string.h>

int main() 
{
	student max = {1234, "Max ustermann", {1.2, 4.3, 1.4}, 3};
	max.id = 4312;
	strncpy(max.name, "Max Mustermann", NAME_LENGTH -1);
	student_print(&max);
}
