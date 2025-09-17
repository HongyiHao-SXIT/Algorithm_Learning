#include <stdio.h>

int main() {
  int var_runoob = 10;
  int *p;
  p = &var_runoob;

  printf("The address of the var_runoob variable: %p\n", p);
  return 0;
}
