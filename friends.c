#include "friends.h"

void initList(int i)
{
  ALL_VERTEX[i].first = (EDGE*)malloc(sizeof(EDGE));
  ALL_VERTEX[i].last = ALL_VERTEX[0].first;
}

void insertVertex(int i, char *reg, char *name, char *links)
{
  VERTEX *new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
  strcpy(new_vertex->reg, reg);
  strcpy(new_vertex->name, name);

  EDGE *new_edge = (EDGE*)malloc(sizeof(EDGE));
  new_edge->data = *new_vertex;
  new_edge->next = NULL;

  initList(i);
  ALL_VERTEX[i].last->next = &new_edge->data;
  ALL_VERTEX[i].last = new_edge;
  // printf("%s - %s\n", ALL_VERTEX[i].last->data.reg, ALL_VERTEX[i].last->data.name);
}

// void processLinks(char *links)
// {
// }

// void findError(char *links)
// {
// }

int main(){
  FILE *pF = fopen("amigos.txt", "r");
  char reg[15], name[50], links[50];
  int count_vertex = 0;

  if(pF != NULL)
  {
    while (fscanf(pF, "%s | %[^|] | %[^\n]", reg, name, links) != EOF)
    {
      insertVertex(count_vertex, reg, name, links);
      ++count_vertex;
    }

    fclose(pF);
  }

  return 0;
}
