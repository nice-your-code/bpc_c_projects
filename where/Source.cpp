#include <stdio.h>
#include <stdbool.h>
#include "vector.h"

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

bool filter1(int * val) {
  return *val > 7;
}

bool filter2(int * val) {
  return *val % 2 == 0;
}

struct vector where(struct vector arr, bool(*f)(int * val)) {
  struct vector out;
  init(&out);
  for (unsigned int i = 0; i < arr.length; i++) {
    if (f(arr.data + i)) {
      push(&out, arr.data[i]);
    }
  }
  del(&arr);
  return out;
}

int main() {
  struct vector vec; init(&vec);
  push(&vec, 2);
  push(&vec, 3);
  push(&vec, 5);
  push(&vec, 8);
  push(&vec, 12);
  push(&vec, 11);
  push(&vec, 14);
  vec = where(vec, filter1);
  vec = where(vec, filter2);

  struct vector check; init(&check);
  push(&check, 8);
  push(&check, 12);
  push(&check, 14);
  messageTest(assert(vec, check));  //show(vec);

  del(&check);
  del(&vec);
  getchar();
  return 0;
}