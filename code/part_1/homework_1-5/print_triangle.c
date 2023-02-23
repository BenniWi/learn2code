#include <stdio.h>

int main(void)
{
    int triangleSize = 0;
    printf("Enter height: ");
    scanf("%d", &triangleSize);

    for (int i = 0; i < triangleSize; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n");

    for (int i = 0; i < triangleSize; ++i)
    {
        for (int j = 1; j <= triangleSize + i; ++j)
        {
            if ((triangleSize - i) > j)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}
