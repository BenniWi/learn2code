#include <stdio.h>

int main()
{
    printf("Enter a decimal number: ");

    int userInput = 0;
    scanf("%d", &userInput);

    unsigned long long result = 0;

    int factor = 1;
    while(userInput > 0) {
        if(userInput % 2) {
            result += factor;
        }
        factor *= 10;
        userInput /= 2;
    }

    printf("Binary form: %llu", result);
}