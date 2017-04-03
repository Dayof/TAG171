/** @file friends.cpp
 *  @brief Main file.
 *
 *  This file contains all the functions and variables
 *  to fully execute the first project of TAG 2017/1.
 *
 *  @author Dayanne Fernandes da Cunha 13/0107191
 *  @bug No bug known.
 */

#include "friends.inl"

/**
 * A function to print a specific main vertex of the graph and its neighbours.
 * @param graph_list vector of pairs of pairs that represents a node and
 *                    its neighbours
 *
 * @return void
 */
void printMainVertex (vector<pair<int, pair<string, string> > > graph_list)
{
  for (int j=0; j < graph_list.size() ; ++j)
    cout << graph_list[j].first << " , " << graph_list[j].second.first << ", " << graph_list[j].second.second << endl;

  cout << "-----------------" << endl;
}

/**
 * A function to print all main vertex and its neighbours of the graph.
 * @param graph_list vector of vectors of pairs of pairs that represents all
 *                    the graph
 *
 * @return void
 */
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

/**
 * A function to print all degress of each vertex of the graph.
 *
 * @return void
 */
void printAllDegress ()
{
  for (int j=0; j < DEGREES.size() ; ++j)
    cout << ALL_GRAPH[DEGREES[j].first][0].second.first << " has " << DEGREES[j].second << " friends." << endl;
}

/**
 * A function to print one clique of the graph.
 * @param clique vector that contains integers representing each vertex of the *                clique
 *
 * @return void
 */
void printClique(vector<int> clique)
{
  for(int k = 0; k < clique.size(); ++k)
    cout << clique[k] << " ";
}

/**
 * A function to print all cliques of the graph.
 *
 * @return void
 */
void printAllCliques()
{
  for(auto c : ALL_CLIQUES)
  {
    for(auto v : c)
      cout << v << " ";
    cout << endl << "-----" << endl;;
  }
}

/**
 * A function to process every link from each vertex of the graph. All links
 *  are saved on a vector of strings of links collected from this main file,
 *  then here it is process each char to make the reference of every link that
 *  one person has with another.
 *
 * @return void
 */
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

/**
 * A function to insert each link that a vertex has on the graph.
 * @param i integer that represents the main vertex to insert the link
 * @param location integer that represents the location of the linked
 * @param reg string that represents the registration of the person linked
 *            with the main vertex
 * @param name string that represents the name of the person linked with the
 *             main vertex
 *
 * @return void
 */
void insertLinksOnVertex(int i, int location, string reg, string name)
{
  for (int j = 1; j < ALL_GRAPH[i].size(); ++j)
    if(ALL_GRAPH[i][j].second.first == reg)
      return;

  ALL_GRAPH[i].push_back(make_pair(location, make_pair(reg, name)));
}

/**
 * A function to insert each main vertex on the main vector.
 * @param i  integer that represents the location of this main vertex
 * @param reg string that represents the registration of the main vertex
 * @param name string that represents the name of the main vertex
 *
 * @return void
 */
void insertVertex(int i, string reg, string name)
{
  ALL_GRAPH[i].push_back(make_pair(i, make_pair(reg,name)));
}

/**
 * A function to save all links from each main vertex. This is used to insert
 *  every link into every main vertex after they are all process to exist their
 *  reference first.
 * @param links string that represents the links of a main vertex
 *
 * @return void
 */
void insertLinks(string links)
{
  LINKS.push_back(links);
}

/**
 * A function to count all degrees of every main vertex. Is sorted from highest
 *  grade to lowest.
 *
 * @return void
 */
void countDegrees()
{
  for(int i = 0; i < ALL_GRAPH.size(); ++i)
    DEGREES[i] = make_pair(i, ALL_GRAPH[i].size()-1) ;

  sort(DEGREES.begin(), DEGREES.end(), desc);
}

/**
 * A function to perfom the union operation with with the first set and a
 *  element.
 * @param first vectors of integers that represents the set that will perform a
 *               union operation with the second parameter
 * @param second integer that represents the element to be add on the first
 *                parameter
 *
 * @return vector<int> the vectors of integers with the second parameter added
 */
vector<int> uni(vector<int> first, int second)
{
  first.push_back(second);
  return first;
}

/**
 * A function to perfom the intersection operation with the first set and the
 *  neighbours of the second element.
 * @param conf vectors of integers that represents the set that will perform a
 *               intersection operation with the neighbours of the second
 *              parameter
 * @param v integer that represents the element which will be the link to find
 *          its neighbours
 *
 * @return vector<int> the vectors of integers with the new set generated from
 *                       the intersection operation
 */
vector<int> intersec(vector<int> conf, int v)
{
  vector<int> newfirst;

  for(int k = 0; k < conf.size(); ++k)
    for(int l = 1; l < ALL_GRAPH[v].size(); ++l)
      if(conf[k] == ALL_GRAPH[v][l].first)
        newfirst.push_back(conf[k]);

  return newfirst;
}

/**
 * A function that calculate all the maximals cliques of a graph.
 * @param R vectors of integers that represents a possibly clique
 * @param P vectors of integers that represents vertices adjacent to every
 *          vertex currently in R, none/few/all when added to R makes it
 *          maximal
 * @param X vectors of integers that represents nodes already in some clique
 *          or processed (to remove duplicate cliques)
 *
 * @return void
 */
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

/**
 * A function to prepared data to calculate all the maximals cliques of a graph.
 *
 * @return void
 */
void prepareBron()
{
  vector<int> R, P, X;

  for(int i = 0; i < MAX_VERTEX; i++)
    P.push_back(i);

  bron(R, P, X);
}

/**
 * A function that sort the maximum cliques to be shown.
 *
 * @return void
 */
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

/**
 * A function to clear the terminal and format better the menu of options.
 *
 * @return void
 */
void clearScreen()
{
  cout << string( 100, '\n' );
}

/**
 * A function to show the menu of options on terminal.
 *
 * @return void
 */
void menu()
{
  int key;
  bool cont = true;

  cin.clear();
  fflush(stdin);

  do{
    clearScreen();
    cout << "Olá professor!!" << endl;
    cout << "----------" << endl << "Qual ação deseja realizar?" << endl << endl;
    cout << "1. Mostrar todos os graus de conexão dos alunos" << endl;
    cout << "2. Mostrar os maiores cliques" << endl;
    cout << "3. Sair do sistema" << endl;
    cin >> key;
    switch (key)
    {
      case 1:
        printAllDegress();
        cont = false;
        break;
      case 2:
        printAllCliques();
        cont = false;
        break;
      case 3:
        cont = false;
        break;
      default:
        cout << "Opção incorreta! Tente digitar novamente.." << endl;
        cout << "Press enter to continue.." << endl;
        getchar();
    }
  }while(cont);
}

/**
 * Main function. Read, load and execute all main functionalities of the
 *  program.
 *
 * @return int 0 represents good exit, -1 represents bad exit
 */
int main()
{
  FILE *pF = fopen("amigos.txt", "r");
  char reg[15], name[50], links[50];
  string sreg, sname, slinks;
  int count_vertex = 0;

  for(int k = 0; k < MAX_VERTEX; ++k)
    ALL_GRAPH[k].reserve(MAX_VERTEX-1);

  if(pF == NULL)
  {
    cout << "Error on open the file." << endl;
    return -1;
  }

  while (fscanf(pF, "%s | %[^|] | %[^\n]", reg, name, links) != EOF)
  {
    sreg = reg;
    sname = name;
    slinks = links;
    insertVertex(count_vertex, sreg, sname);
    insertLinks(slinks);
    ++count_vertex;
  }

  processLinks();
  countDegrees();
  prepareBron();
  getMaxCliques();

  menu();

  fclose(pF);

  return 0;
}
