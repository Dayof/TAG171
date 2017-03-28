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

void initStack()
{
  for(int i = 0; i< MAX_VERTEX; ++i)
    ALL_CHECK_VERTEX[i].data = NULL;
}

void insertLinks(int i, char *links)
{
  strcpy(ALL_LINKS[i], links);
}

int emptyList(int i)
{
  return (ALL_VERTEX[i].first->next == NULL);
}

void insertLinksOnVertex(int vert, int adj)
{
  ALL_VERTEX[vert].last->next = (EDGE*)malloc(sizeof(EDGE));
  ALL_VERTEX[vert].last = ALL_VERTEX[vert].last->next;
  strcpy(ALL_VERTEX[vert].last->data.reg,  ALL_VERTEX[adj].first->data.reg);
  strcpy(ALL_VERTEX[vert].last->data.name,  ALL_VERTEX[adj].first->data.name);

  if(emptyList(vert)) ALL_VERTEX[vert].first->next = ALL_VERTEX[vert].last;

  ALL_VERTEX[vert].last->next = NULL;
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

  if(emptyList(i)) printf("SEM AMIGOS\n");
  else
  {
    printf("------ AMIGOS\n");
    temp = ALL_VERTEX[i].first->next;
    do{
      printf("Matrícula : %s - Nome : %s\n\n", temp->data.reg, temp->data.name);
      temp = temp->next;
    }while(temp != NULL);

    printf("------ END\n");
  }
}

void printLastOnStack()
{
  for(int i = 0; i < ALL_CHECK_VERTEX[SIZE_STACK].size_tuple; ++i)
    printf("Reg: %s \n", ALL_CHECK_VERTEX[SIZE_STACK].data[i].second);
}

void pop()
{
  ALL_CHECK_VERTEX[SIZE_STACK].data = NULL;
  --SIZE_STACK;
}

// LIST OF TUPLE -> [ORIGIN VERTEX, ADJ REG]
void push(TUPLE *node, int size_tuple)
{
  ALL_CHECK_VERTEX[SIZE_STACK].data = node;
  ALL_CHECK_VERTEX[SIZE_STACK].size_tuple = size_tuple;
  ALL_CHECK_VERTEX[SIZE_STACK].next = NULL;
  if(SIZE_STACK) ++SIZE_STACK;
}

int size(NEXT node)
{
  int result = 0;
  NEXT temp;

  temp = node->next;

  while(temp != NULL)
  {
    ++result;
    temp = temp->next;
  }

  return result;
}

// depth search
void countDegrees()
{
  NEXT temp;
  int vertex_index = 0;

  temp = ALL_VERTEX[vertex_index].first;
  ALL_CHECK_VERTEX[SIZE_STACK].data = (TUPLE*)malloc(sizeof(TUPLE));
  for(int j = 0; j < size(temp) && temp != NULL; ++j)
  {
    ALL_CHECK_VERTEX[SIZE_STACK].data[j].first = vertex_index;
    strcpy(ALL_CHECK_VERTEX[SIZE_STACK].data[j].second, temp[vertex_index].data.reg);
    temp = temp->next;
  }

  // do{
  //   printf("Matrícula : %s - Nome : %s\n\n", temp->data.reg, temp->data.name);
  //   temp = temp->next;
  // }while(temp != NULL);

  // printf("%d\n", VISITED_VERTEX[15]);
  // while()
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
    initStack();

    // countDegrees();
    //printAllVertex();
    //printOneVertex(37);

    // test size
    // printf("%d\n", size(node));

    // test size
    // push stack
    // TUPLE node[10];
    // node[0].first = 0;
    // char *reg = "130107191";
    // strcpy(node[0].second, reg);
    //
    // node[1].first = 0;
    // char *reg2 = "110027931";
    // strcpy(node[1].second, reg2);
    //
    // push(node, 2);
    // printf("%d\n", SIZE_STACK);
    // printLastOnStack();

    fclose(pF);
  }

  return 0;
}
