#include <iostream>
#include <sstream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

#define MAX_VERTEX 39

using namespace std;

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
    cout << clique[k] << " " << endl;

  cout << " ------ NEXT CLIQUE ------- " << endl;
}

vector<int> uni(vector<int> first, int second)
{
  first.push_back(second);

  return first;
}

vector<int> intersec(vector<vector<int> > graph, vector<int> conf, int second)
{
  vector<int> newfirst;

  for(int k = 0; k < conf.size(); ++k)
  {
    for(int l = 0; l < graph[second].size(); ++l)
    {
      if(conf[k] == graph[second][l])
      {
        newfirst.push_back(conf[k]);
      }

    }
  }

  return newfirst;
}

void bron(vector<vector<int> > graph, vector<int> R,vector<int> P,vector<int> X)
{
  vector<int> newr, newp, newx;

  if(P.empty() && X.empty())
  {
    cout << "R maximal" << endl;
    printClique(R);
  }
  else
  {
    for(int v : P)
    {
      newr = uni(R, v);
      newp = intersec(graph, P, v);
      newx = intersec(graph, X, v);
      bron(graph, newr, newp , newx);
      P.erase(remove(P.begin(), P.end(), v), P.end());
      X.push_back(v);
    }
  }
}

void prepareBron()
{
  vector<int> R, P, X;
  vector<vector<int> > graph(4);

  graph[0].push_back(1);
  graph[0].push_back(2);
  graph[1].push_back(0);
  graph[1].push_back(2);
  graph[1].push_back(3);
  graph[2].push_back(0);
  graph[2].push_back(1);
  graph[3].push_back(1);

  for(int i = 0; i < 4; i++)
    P.push_back(i);

  bron(graph, R, P, X);
}

int main()
{
  prepareBron();

  return 0;
}
