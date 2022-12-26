#include <stdio.h>  //specify where to look for the functions you need

int main()
{
  int x; // defines an integer variable named x
  float y = 1.0; // defines a variable and assings a value

  x = 5; // initialize x bevor first usage
  x = x+x; // re-assign a value to x 

  printf("Hello World!\n");
  printf("x is %d, y is %.2f and a char is %c\n", x, y, 'a');

  return 0;
}
