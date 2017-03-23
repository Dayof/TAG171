#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 39

typedef struct vertex{
  char reg[15];
  char name[50];
}VERTEX;

typedef struct edge *NEXT;
typedef struct edge{
  VERTEX data;
  NEXT next;
}EDGE;

typedef struct list{
  NEXT first, last;
}LIST;

LIST ALL_VERTEX[MAX_VERTEX];
char ALL_LINKS[MAX_VERTEX][50];

void insertVertex(int, char*, char*);
void insertLinks(int, char*);
int emptyList(int);
void insertLinksOnVertex(int, int);
void processLinks();
void printAllVertex();
void printOneVertex(int);
