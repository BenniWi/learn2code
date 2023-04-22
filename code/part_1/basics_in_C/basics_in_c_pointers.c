#include <stdio.h>  //specify where to look for the functions you need

int main(void)
{
    {
        int i, j;
        int *p;  // define pointer to integer. p holds a random unknown address now
        // trying to use *p most probably creates a seg fault
        int *pi = NULL;  // now pointer is initialized. Still a segfault, but we can check it
        printf("uninitialized: p points to: %p\n", p);  // %p is "pointer address"
        p = &i;                                         // assign the address of i to p
        printf("initialized p, uninitialized i: value *p=%d, p points to %p\n", *p, p);
        *p = 5;  // assign value to the memory of the pointer
        printf("initialized p, initialized i: value *p=%d, p points to %p\n", *p, p);
        j = i;  // copy the value from i to j
        printf("i=%d, j=%d, value *p=%d, p points to %p\n", i, j, *p, p);
    }

    {
        struct my_struct
        {
            int a;
            float b;
        } my1 = {.a = 2, .b = 3.3f};
        struct my_struct *p_my2 = &my1;
        // accessing elements of pointer-to-struct is done by "->" instead of "."
        printf("Struct value a=%i from instance; struct value b=%.1f from pointer!\n", my1.a, p_my2->b);
    }

    {
        printf("size of char: %lu\n", sizeof(char));
        printf("size of int: %lu\n", sizeof(int));
        printf("size of float: %lu\n", sizeof(float));
        printf("size of double: %lu\n", sizeof(double));
        printf("size of long: %lu\n", sizeof(long));

        printf("size of char*: %lu\n", sizeof(char *));
        printf("size of int*: %lu\n", sizeof(int *));
        printf("size of float*: %lu\n", sizeof(float *));
        printf("size of double*: %lu\n", sizeof(double *));
        printf("size of long*: %lu\n", sizeof(long *));
    }

    return 0;
}
