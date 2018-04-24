#pragma once
struct vector
{
  int * data;
  unsigned int length;
  unsigned int capasity;
  float multipler;
};
void init(struct vector * vec);
void del(struct vector * vec);
void push(struct vector * vec, int a);