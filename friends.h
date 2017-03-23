#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX 39

typedef struct vertex{
  char reg[15];
  char name[50];
}VERTEX;

typedef struct edge{
  VERTEX data, *next;
}EDGE;

typedef struct list{
  EDGE *first, *last;
}LIST;

LIST ALL_VERTEX[MAX_VERTEX];
