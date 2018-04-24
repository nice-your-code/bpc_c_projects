#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int n, k = 0;
  scanf("%d", &n);
  while (n > 1)
  {
    n = (n + 1) / 2;
    k++;
  }
  printf("%d", k);
  //getchar();
  //getchar();
  return 0;
}