#include "friends.h"

// void addInVertices()
// {
// }

// void processLinks(char *links)
// {
// }

int main(){
  FILE *pF = fopen("amigos.txt", "r");
  char mat[15], nome[50], links[50];

  if(pF != NULL)
  {
    while (fscanf(pF, "%s | %[^|] | %[^\n]", mat, nome, links) != EOF)
    printf("%s - %s - %s\n", mat, nome, links);
    fclose(pF);
  }

  return 0;
}
