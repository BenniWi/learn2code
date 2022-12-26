#include <stdio.h>

int main(void) 
{

  int value = 90;
  int percentage = 11;

  printf("%d%% of %d = %.2f\n", percentage, value, (double)percentage * (double)value / 100.0f );
}
