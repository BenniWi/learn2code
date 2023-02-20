#include <stdio.h>  //scanf is also part of stdio

int main()
{
    // define our variables
    int val1, val2, res;
    // read in the first value
    printf("Enter the first value: ");
    scanf("%d", &val1);
    // read in the second value
    printf("Enter the second value: ");
    scanf("%d", &val2);
    // calculate the result
    res = val1 + val2;
    // print the result
    printf("%d + %d = %d \n", val1, val2, res);
    return 0;
}
