#include "friends.inl"

void printMainVertex (vector<pair<int, pair<string, string> > > graph_list)
{
  for (int j=0; j < graph_list.size() ; ++j)
    cout << graph_list[j].first << " , " << graph_list[j].second.first << ", " << graph_list[j].second.second << endl;

  cout << "-----------------" << endl;
}

void printAllVertex (vector<vector<pair<int, pair<string, string> > > >  graph_list)
{
  for(int i = 0; i < graph_list.size(); ++i)
  {
    cout << "------ MAIN PERSON -------" << endl;
    cout << graph_list[i][0].first << " : " << graph_list[i][0].second.first << ", " << graph_list[i][0].second.second << endl;
    cout << "-----------------" << endl;
    for (int j = 1; j < graph_list[i].size() ; ++j)
    {
      cout << graph_list[i][j].first << " : " << graph_list[i][j].second.first << ", " << graph_list[i][j].second.second << endl;
    }
  }
}

void printAllDegress ()
{
  for (int j=0; j < DEGREES.size() ; ++j)
    cout << ALL_GRAPH[DEGREES[j].first][0].second.first << " has " << DEGREES[j].second << " friends." << endl;
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
          insertLinksOnVertex(i, str_num-1, ALL_GRAPH[str_num-1][0].second.first, ALL_GRAPH[str_num-1][0].second.second);
          insertLinksOnVertex(str_num-1, i, ALL_GRAPH[i][0].second.first, ALL_GRAPH[i][0].second.second);
        }
      }
    }
  }
}

void insertLinksOnVertex(int i, int location, string reg, string name)
{
  for (int j = 1; j < ALL_GRAPH[i].size(); ++j)
  {
    if(ALL_GRAPH[i][j].second.first == reg)
      return;
  }
  ALL_GRAPH[i].push_back(make_pair(location, make_pair(reg, name)));
}

void insertVertex(int i, string reg, string name, string links)
{
  ALL_GRAPH[i].push_back(make_pair(i, make_pair(reg,name)));
}

void insertLinks(string links)
{
  LINKS.push_back(links);
}

void countDegrees()
{
  for(int i = 0; i < ALL_GRAPH.size(); ++i)
    DEGREES[i] = make_pair(i, ALL_GRAPH[i].size()-1) ;

  sort(DEGREES.begin(), DEGREES.end(), desc);
}

void printState(vector<int> R, vector<int> P, vector<int> X)
{
  cout << "BEGIN STATE" << endl;

  cout << "R :" << endl;
  for(int k = 0; k < R.size(); ++k)
    cout << R[k] << " " << endl;

  cout << endl;

  cout << "P :" << endl;
  for(int k = 0; k < P.size(); ++k)
    cout << P[k] << " " << endl;

  cout << endl;

  cout << "X :" << endl;
  for(int k = 0; k < X.size(); ++k)
    cout << X[k] << " " << endl;

  cout << endl;

  cout << "END STATE" << endl;
}

void printClique(vector<int> clique)
{
  for(int k = 0; k < clique.size(); ++k)
    cout << clique[k] << " ";
}

void printAllCliques()
{
  for(auto c : ALL_CLIQUES)
  {
    for(auto v : c)
      cout << v << " ";
    cout << endl << "-----" << endl;;
  }
}

vector<int> uni(vector<int> first, int second)
{
  first.push_back(second);
  return first;
}

vector<int> intersec(vector<int> conf, int v)
{
  vector<int> newfirst;

  for(int k = 0; k < conf.size(); ++k)
    for(int l = 1; l < ALL_GRAPH[v].size(); ++l)
      if(conf[k] == ALL_GRAPH[v][l].first)
        newfirst.push_back(conf[k]);

  return newfirst;
}

void bron(vector<int> R,vector<int> P,vector<int> X)
{
  vector<int> newr, newp, newx;

  if(P.empty() && X.empty())
    ALL_CLIQUES.insert(R);
  else
  {
    for(int v : P)
    {
      newr = uni(R, v);
      newp = intersec(P, v);
      newx = intersec(X, v);
      bron(newr, newp , newx);
      P.erase(remove(P.begin(), P.end(), v), P.end());
      X.push_back(v);
    }
  }
}

void prepareBron()
{
  vector<int> R, P, X;

  for(int i = 0; i < MAX_VERTEX; i++)
    P.push_back(i);

  bron(R, P, X);
}

void getMaxCliques()
{
  set<vector<int> > new_all_cliques;
  int maxc = 0;

  for(auto c : ALL_CLIQUES)
    if(c.size() > maxc)
      maxc = c.size();

  for(auto c : ALL_CLIQUES)
    if(c.size() == 6)
      new_all_cliques.insert(c);

  ALL_CLIQUES = new_all_cliques;
}

// void menu()
// {
//   char *key;
//
//   cout << "Olá professors!!" << endl;
//   cout << "----------" << endl << "Qual ação deseja realizar?" << endl << endl;
//   cout << "1. Mostrar todos os graus de conexão dos alunos" << endl;
//   cout << "2. Mostrar os maiores cliques" << endl;
//   cint >> key;
//   while(key == 1 || key == 2)
//   {
//
//   }
// }

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
  // printAllVertex(ALL_GRAPH);
  countDegrees();
  // printAllDegress();
  prepareBron();
  getMaxCliques();
  // printAllCliques();

  menu();

  return 0;
}
