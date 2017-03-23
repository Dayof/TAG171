#include "friends.h"

void insertVertex(int i, char *reg, char *name, char *links)
{
  VERTEX *new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
  strcpy(new_vertex->reg, reg);
  strcpy(new_vertex->name, name);

  EDGE *new_edge = (EDGE*)malloc(sizeof(EDGE));
  new_edge->data = *new_vertex;
  new_edge->next = NULL;

  ALL_VERTEX[i].first = (EDGE*)malloc(sizeof(EDGE));
  ALL_VERTEX[i].first = new_edge;
  ALL_VERTEX[i].last = ALL_VERTEX[i].first;
  // printf("%s - %s\n", ALL_VERTEX[i].first->data.reg, ALL_VERTEX[i].last->data.reg);
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
