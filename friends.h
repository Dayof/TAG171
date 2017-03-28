#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 39

typedef struct vertex{
  char reg[15], name[50];
}VERTEX;

typedef struct edge *NEXT;
typedef struct edge{
  VERTEX data;
  NEXT next;
}EDGE;

typedef struct list{
  NEXT first, last;
}LIST;

typedef struct tuple{
  int first;
  char second[15];
}TUPLE;

typedef struct stack *POINTER;
typedef struct stack{
  TUPLE *data;
  int size_tuple;
  POINTER next;
}STACK;

LIST ALL_VERTEX[MAX_VERTEX];
STACK ALL_CHECK_VERTEX[MAX_VERTEX];
char ALL_LINKS[MAX_VERTEX][50];
int VISITED_VERTEX[MAX_VERTEX] = {0};
int SIZE_STACK = 0;

void insertVertex(int, char*, char*);
void insertLinks(int, char*);
int emptyList(int);
void insertLinksOnVertex(int, int);
void processLinks();
void printAllVertex();
void printOneVertex(int);
