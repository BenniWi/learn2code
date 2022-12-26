
int main()
{
  int a[5]; // declare an array without initialization
  int b[5] = {0}; // initialize all values with zeros
  int c[5] = {22, 33, 44, 55, 66}; // initialize alle values explicitly
  int d[] = {22, 33, 44, 55, 66};  // you don't need to specify the size
  int e[5];
  e[0] = 10; // !!! array indices always start at 0 ....
  e[1] = 3;
  e[2] = 13;
  e[3] = 22;
  e[4] = 77; // ... and end with n-1

  return 0;
}
