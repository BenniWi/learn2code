#include <stdio.h>  //specify where to look for the functions you need

// globally defined structure
struct outer_struct
{
    int a, b, c;
    float d, e, f;
};

// declare a new type of structure
typedef struct
{
    int a, b, c;
    float d, e, f;
} outer_td_struct;

int main()
{
    // locally instantiated structure with direct initialization
    struct outer_struct or = {.a = 5, .b = 6, .c = 7, .d = 0.1, .e = 0.2, .f = 0.3};

    // using the new type of structure
    outer_td_struct otd = {.a = 5, .b = 6, .c = 7, .d = 0.1, .e = 0.2, .f = 0.3};

    // locally defined structure
    struct inner_struct
    {
        int g, h, i;
        float j, k, l;
    } ir;  // directly instantiated, but without initialization -> be careful

    // initialization of the ir structure
    ir.g = 9;
    ir.h = 8;
    ir.i = 7;
    ir.j = 1.1;
    ir.k = 1.2;
    ir.l = 1.3;

    // print outer structure
    printf("outer struct is: a=%i, b=%i, c=%i, d=%f, e=%f, f=%f\n", or.a, or.b, or.c, or.d, or.e, or.f);
    // print outer typedef structure
    printf("outer td struct is: a=%i, b=%i, c=%i, d=%f, e=%f, f=%f\n", otd.a, otd.b, otd.c, otd.d, otd.e, otd.f);
    // print inner structure
    printf("inner struct is: a=%i, b=%i, c=%i, d=%f, e=%f, f=%f\n", ir.g, ir.h, ir.i, ir.j, ir.k, ir.l);

    return 0;
}
