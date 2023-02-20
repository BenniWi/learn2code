#include <stdio.h>
// example from problems with implicit cast
// enable warnings with the gcc flag "-Wconversion"
int main(void)
{
    int b = 2;
    float a = 5.0F;
    a = 5.0 / b;
    printf("float a = %.3f\n", a);  // seems to work correctly -> a = 2.500

    a = 5 / b;
    printf("float a = %.3f\n", a);  // definitely wrong output -> a = 2.000
}
