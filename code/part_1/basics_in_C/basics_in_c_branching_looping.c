#include <stdio.h>  //specify where to look for the functions you need

int main(void)
{
    /*we can open a new "scope" everywhere in the code
      what happens in the scope, stays in the scope
    */

    {  // the "if" example
        printf("\nstarting the \"if\" example\n");
        int b = 0;
        if (b < 0)
        {
            printf("The value is negative\n");
        }
        else if (b == 0)
        {
            printf("The value is zero\n");
        }
        else
        {
            printf("The value is positive\n");
        }
    }

    {  // the "switch" example
        printf("\nstarting the \"switch\" example\n");
        int a = 2;
        switch (a)
        {
            case 1:
                printf("a is one\n");
                break;
            case 2:
                printf("a is two\n");
                break;
            case 3:
                printf("a is three\n");
                break;
            default:
                printf("a is something else\n");
                break;
        }
    }

    {  // the "while" example
        printf("\nstarting the \"while\" example\n");
        {
            int a = 0, b = 10;
            while (a < b)
            {
                printf("while: %d\n", a);
                ++a;
            }
        }
        {
            int a = 0, b = 10;
            do
            {
                printf("do while: %d\n", a);
                ++a;
            } while (a < b);
        }
    }

    {  // the "for" example
        printf("\nstarting the \"for\" example\n");
        {
            int a = 0, b = 10;
            while (a < b)
            {
                printf("while: %d\n", a);
                ++a;
            }
        }
        {
            int a, b;
            for (a = 0, b = 10; a < b; ++a)
            {
                printf("for: %d\n", a);
            }
        }
    }

    return 0;
}
