#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct vector
{
  int * data;
  unsigned int length;
};

void messageTest(bool t) {
  if (t) {
    printf("Test pass succesful\n");
  }
  else {
    printf("Test failed\n");
  }
}
bool assert(struct vector a, struct vector b) {
  if (a.length != b.length) {
    return false;
  }
  for (unsigned int i = 0; i < a.length; i++) {
    if (a.data[i] != b.data[i]) {
      return false;
    }
  }
  return true;
}

void show(struct vector arr) {
  for (unsigned int i = 0; i < arr.length; i++) {
    printf("%d ", arr.data[i]);
  }
  printf("\n");
}

void map(struct vector arr, void(*f)(int * val)) {
  for (unsigned int i = 0; i < arr.length; i++) {
    f(arr.data + i);
  }
}


void sqr(int * val) {
  *val *= *val;
}
void mul2(int * val) {
  *val *= 2;
}
void plus3(int * val) {
  *val += 3;
}


int main() {
  int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
  unsigned int length1 = 10;
  int a2[5] = { 1, 2, 3, 4 ,5 };
  unsigned int length2 = 5;

  struct vector v1;
  v1.data = a1; v1.length = length1;
  struct vector v2;
  v2.data = a2; v2.length = length2;

  int check_a1[10] = { 1, 4, 9, 16, 25, 36, 49, 64, 81, 100 };
  int check_a2[10] = { 2, 8, 18, 32, 50, 72, 98, 128, 162, 200 };
  int check_a3[10] = { 5, 11, 21, 35, 53, 75, 101, 131, 165, 203 };
  struct vector check1; check1.data = check_a1;  check1.length = length1;
  struct vector check2; check2.data = check_a2;  check2.length = length1;
  struct vector check3; check3.data = check_a3;  check3.length = length1;

  map(v1, sqr);
  messageTest(assert(check1, v1)); //show(v1);
  map(v1, mul2);
  messageTest(assert(check2, v1)); //show(v1);
  map(v1, plus3);
  messageTest(assert(check3, v1)); //show(v1);
  getchar();
}