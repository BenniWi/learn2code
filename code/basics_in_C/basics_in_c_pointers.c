#include <stdio.h>  //specify where to look for the functions you need

int main()
{
    {
        int i, j;
        int *p; // define pointer to integer. p holds a random unknown address now
        // trying to use *p most probably creates a seg fault
        printf("uninitialized: p points to: %lu\n", p); // %lu is "long unsigned" 
        p = &i; // assign the address of i to p
        printf("initialized p, uninitialized i: value *p=%d, p points to %lu\n", *p, p);
        *p = 5; // assign value to the memory of the pointer
        printf("initialized p, initialized i: value *p=%d, p points to %lu\n", *p, p);
        j=i;    // copy the value from i to j
        printf("i=%d, j=%d, value *p=%d, p points to %lu\n", i, j, *p, p);
    }

    {
        printf("size of char: %d\n", sizeof(char));
        printf("size of int: %d\n", sizeof(int));
        printf("size of float: %d\n", sizeof(float));
        printf("size of double: %d\n", sizeof(double));
        printf("size of long: %d\n", sizeof(long));

        printf("size of char*: %d\n", sizeof(char*));
        printf("size of int*: %d\n", sizeof(int*));
        printf("size of float*: %d\n", sizeof(float*));
        printf("size of double*: %d\n", sizeof(double*));
        printf("size of long*: %d\n", sizeof(long*));
    }

    return 0;
}
