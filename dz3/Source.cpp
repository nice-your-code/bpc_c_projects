#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int a[101][2][101];

int main() {
  int n;
  scanf("%d", &n);
  a[0][0][1] = 1;
  a[0][1][1] = 1;

  for (int i = 1; i <= n; i++) {
    int razrad = 0;
    for (int j = 1; j < 100; j++) {
      a[i][0][j] = (a[i - 1][0][j] + a[i - 1][1][j] + razrad) % 10;
      razrad = (a[i - 1][0][j] + a[i - 1][1][j] + razrad) / 10;
      a[i][1][j] = a[i - 1][0][j];
    }
  }
  bool t = false;
  for (int j = 100; j > 0; j--) {
    if (a[n][0][j] != 0 || t) {
      printf("%d", a[n][0][j]);
      t = true;
    }
  }
  getchar();
  getchar();
  return 0;
}
/*
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long a[101][2];

int main() {
int n;
scanf("%d", &n);
a[0][0] = 1;
a[0][1] = 1;
for (int i = 1; i <= n; i++) {
a[i][0] = a[i - 1][0] + a[i - 1][1];
a[i][1] = a[i - 1][0];
}
printf("%lld", a[n][0]);
getchar();
getchar();
return 0;
}

*/