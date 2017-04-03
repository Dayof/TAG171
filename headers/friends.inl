/** @file friends.inl
 *  @brief Arquivos de bibliotecas em comum
 *  dos arquivos de entidade e domínio.
 *
 *  Neste arquivo contém os includes de
 *  bibliotecas gerais do C++ como também
 *  as assinaturas de todas funções a serem
 *  utilizadas neste projeto e tipos de dados
 *  globais.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef HEADERS_INL_INCLUDED
#define HEADERS_INL_INCLUDED

/* -- Bibliotecas necessárias para o bom funcionamento do sistema -- */

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

using namespace std;

/* ----------- Definições de todas as funções do sistema ----------- */

/* -- Definições de funções para mostrar dados na tela do terminal -- */

void printAllVertex (vector<vector<pair<int, pair<string, string> > > >);
void printMainVertex (vector<pair<int, pair<string, string> > >);
void printAllDegress ();
void printAllCliques();
void printClique(vector<int>);

/* -- Definições de funções para criação e população do grafo base -- */

void insertVertex(int, string, string, string);
void insertLinks(string);
void processLinks();
void insertLinksOnVertex(int, int, string, string);

/* -- Definição da função para contar graus de cada vértice do grafo base -- */

void countDegrees();

/* -- Definições de funções para executar o algoritmo de Bron-Kerbosch -- */

vector<int> uni(vector<int>, int);
vector<int> intersec(vector<int>, int);
void bron(vector<int>,vector<int>,vector<int>);
void prepareBron();

/* -- Definições de TADs -- */

#define MAX_VERTEX 39

vector<vector<pair<int, pair<string, string> > > > ALL_GRAPH(MAX_VERTEX);
vector<pair<int, int> > DEGREES(MAX_VERTEX);
set<vector<int> > ALL_CLIQUES;
vector<string> LINKS;

/* -- Definição de função de comparação para realizar ordenação -- */

bool desc(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second > b.second;
}

#endif // HEADERS_HPP_INCLUDED
