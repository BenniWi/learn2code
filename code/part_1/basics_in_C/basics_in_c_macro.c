#include <stdio.h>  //specify where to look for the functions you need

// define a macro, from now on we can use "new_line" instead of "\n"
#define new_line "\n"

int main(void)
{
    // append the macro to the string
    printf("Hello World!" new_line);
    return 0;
}
