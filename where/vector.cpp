#include "vector.h"
#include <stdlib.h>

void init(struct vector * vec)
{
  (*vec).capasity = 1;
  (*vec).length = 0;
  (*vec).multipler = 2;
  (*vec).data = (int*)malloc(sizeof(int) * (*vec).capasity);
}

void del(struct vector * vec)
{
  free((*vec).data);
}

void push(struct vector * vec, int a)
{
  if ((*vec).length == (*vec).capasity) {
    (*vec).capasity *= (*vec).multipler;
    int * new_data = (int*)realloc((*vec).data, sizeof(int) * (*vec).capasity);
    if (new_data) {
      (*vec).data = new_data;
    }
    else {
      // TODO недостаточно памяти!
      free((*vec).data);
    }
  }
  (*vec).data[(*vec).length++] = a;
}