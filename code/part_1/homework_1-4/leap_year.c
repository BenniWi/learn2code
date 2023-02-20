#include <stdio.h>

int main(void)
{
    printf("Please enter a year: ");

    unsigned int year = 0;

    // read in the year from the command line
    scanf("%u", &year);

    /*
      A year is always a leap year, if it is a multiple of 400! -> year % 400 == 0
      A year is a leap year, if it is a multiple of 4 -> (year % 4 == 0)
      A year is NOT a leap year, if it is a multiple of 100 -> (year % 100 != 0)
      2008 -> yes
      1900 -> no
      2100 -> no
      2000 -> yes
      2020 -> yes
    */

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        printf("%u is a leap year\n", year);
    }
    else
    {
        printf("%u is NOT a leap year\n", year);
    }
}
