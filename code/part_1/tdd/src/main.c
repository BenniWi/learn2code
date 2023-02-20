#include "functions.h"
#include <stdio.h>

int main(void)
{
    int val1 = 5;
    int val2 = 6;
    int ret_val = add_integers(val1, val2);

    printf("Result of addition is: %d\n", ret_val);
    return 0;
}
