#include "friends.h"

void insertVertex(int i, char *reg, char *name)
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
}

void insertLinks(int i, char *links)
{
  strcpy(ALL_LINKS[i], links);
}

int emptyList(int i)
{
  return (ALL_VERTEX[i].first == NULL);
}

void insertLinksOnVertex(int vert, int adj)
{
  // printf("YES %d %d\n", vert, adj);
  // printf("%d on %d, value: %s\n", vert, adj, ALL_VERTEX[vert].last->data.reg);
  ALL_VERTEX[vert].last->next = ALL_VERTEX[adj].first;
  ALL_VERTEX[vert].last = ALL_VERTEX[adj].first;
  ALL_VERTEX[vert].last->next = NULL;
  printOneVertex(vert);
}

void processLinks()
{
  int k = 0, str_num;
  char num[2];

  for(int i=0; i<MAX_VERTEX; ++i)
  {
    for(int j=0; j<sizeof(ALL_LINKS[i]); ++j)
    {

      if(ALL_LINKS[i][j] != ' ' && ALL_LINKS[i][j] != '\n' && ALL_LINKS[i][j] != '\0')
      {
        num[k] = ALL_LINKS[i][j];
        ++k;
      }
      else
      {
        num[k] = '\0';
        str_num = atoi(num);
        k=0;
        if(str_num != -1 && str_num != 0)
          insertLinksOnVertex(i, str_num-1);
      }
    }
  }
}

void printAllVertex()
{
  for(int i=0; i< MAX_VERTEX; ++i)
  {
    printf("------ ALUNO : %d\n", i+1);
    printf("Matrícula : %s - Nome : %s\n\n", ALL_VERTEX[i].first->data.reg,
                                          ALL_VERTEX[i].first->data.name);
  }
}

void printOneVertex(int i)
{
  NEXT temp;

  printf("------ ALUNO : %d\n", i+1);
  printf("Matrícula : %s - Nome : %s\n\n", ALL_VERTEX[i].first->data.reg,
                                        ALL_VERTEX[i].first->data.name);

  if(emptyList(14)) printf("SEM AMIGOS\n");
  else
  {
    printf("------ AMIGOS\n");
    temp = ALL_VERTEX[i].first->next;
    while(temp->next != NULL)
    {
      printf("Matrícula : %s - Nome : %s\n\n", temp->data.reg, temp->data.name);
      temp = temp->next;
    }
  }
}

// TODO Incomplete links
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
      insertVertex(count_vertex, reg, name);
      insertLinks(count_vertex, links);
      ++count_vertex;
    }

    processLinks();
    // printAllVertex();
    // printOneVertex(0);

    fclose(pF);
  }

  return 0;
}
