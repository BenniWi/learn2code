#include <stdio.h>

int add_and_print(int val1, int val2)
{
    int ret_val = val1 + val2;
    printf("Result of addition is: %d + %d = %d\n", val1, val2, ret_val);
    return ret_val;
}

int main(void)
{
    add_and_print(5, 6);
    add_and_print(200, 55);
    add_and_print(2147483647, 1);
    return 0;
}
