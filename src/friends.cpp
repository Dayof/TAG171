#include "friends.inl"

void printMainVertex (vector<pair<string, string> > graph_list)
{
  for (int j=0; j < graph_list.size() ; ++j)
    cout << graph_list[j].first << ", " << graph_list[j].second << endl;

  cout << "-----------------" << endl;
}

void printAllVertex (vector<vector<pair<string, string> > > graph_list)
{
  for(int i = 0; i < graph_list.size(); ++i)
  {
    cout << "------ NEXT PERSON -------" << endl;
    for (int j = 0; j < graph_list[i].size() ; ++j)
    {
      cout << graph_list[i][j].first << ", " << graph_list[i][j].second << endl;
      cout << "-----------------" << endl;
    }
  }
}

void processLinks()
{
  int str_num, n = 0;
  char num[2];

  for(int i=0; i < LINKS.size(); ++i)
  {
    n = 0;
    for(int j=0; j <= LINKS[i].size(); ++j)
    {
      if(LINKS[i][j] != ' ' && LINKS[i][j] != '\n' && LINKS[i][j] != '\0' && j!=LINKS[i].size())
      {
        num[n] = LINKS[i][j];
        ++n;
      }
      else
      {
        num[n] = '\0';
        str_num = atoi(num);
        n=0;
        if(str_num > -1 && str_num <= 39)
        {
          insertLinksOnVertex(i, str_num-1, ALL_GRAPH[str_num-1][0].first, ALL_GRAPH[str_num-1][0].second);
          insertLinksOnVertex(str_num-1, i, ALL_GRAPH[i][0].first, ALL_GRAPH[i][0].second);
        }
      }
    }
  }
}

void insertLinksOnVertex(int i, int location, string reg, string name)
{
  for (int j = 1; j < ALL_GRAPH[i].size(); ++j)
  {
    if(ALL_GRAPH[i][j].first == reg)
      return;
  }
  ALL_GRAPH[i].push_back(make_pair(reg, name));
}

void insertVertex(int i, string reg, string name, string links)
{
  ALL_GRAPH[i].push_back(make_pair(reg,name));
}

void insertLinks(string links)
{
  LINKS.push_back(links);
}

int main()
{
  char reg[15], name[50], links[50];
  string sreg, sname, slinks;
  int count_vertex = 0;

  for(int k = 0; k < MAX_VERTEX; ++k)
    ALL_GRAPH[k].reserve(MAX_VERTEX-1);

  while (scanf("%s | %[^|] | %[^\n]", reg, name, links) == 3)
  {
    sreg = reg;
    sname = name;
    slinks = links;
    insertVertex(count_vertex, sreg, sname, slinks);
    insertLinks(links);
    ++count_vertex;
  }

  processLinks();
  printAllVertex(ALL_GRAPH);

  return 0;
}
