#include <stdio.h>

int main(void)
{
    // define two ints
    int x = 5;
    int y = 4;

    printf("x = %i, y = %i\n", x, y);

    // define two pointers
    int* p_x = &x;
    int* p_y = &y;

    // use the pointers and a temp variable to swap the values
    int temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;

    printf("swapped: x = %i, y = %i\n", x, y);
}
