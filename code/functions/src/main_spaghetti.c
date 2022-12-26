#include <stdio.h>

int main(void)
{
    int val1 = 5;
    int val2 = 6;
    int ret_val = val1 + val2;
    printf("Result of addition is: %d + %d = %d\n", val1, val2, ret_val);

    val1 = 200;
    val2 = 55;
    ret_val = val1 + val2;
    printf("Result of addition is: %d + %d = %d\n", val1, val2, ret_val);

    val1 = 2147483647;
    val2 = 1;
    ret_val = val1 + val2;
    printf("Result of addition is: %d + %d = %d\n", val1, val2, ret_val);
    return 0;
}
