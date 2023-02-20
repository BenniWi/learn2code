#include "functions.h"
#include <stdio.h>

int add_and_print(int val1, int val2)
{
    int ret_val = val1 + val2;
    printf("Result of addition is: %d + %d = %d\n", val1, val2, ret_val);
    return ret_val;
}
