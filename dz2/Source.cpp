#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a = abs(n); int b = abs(k);
  if (a < b) {
    a ^= b ^= a ^= b;
  }
  while (b != 0)
  {
    b ^= a ^= b ^= a = a % b;
  }
  printf("%d %d", n / a, k / a);
  //getchar();
  //getchar();
  return 0;
}