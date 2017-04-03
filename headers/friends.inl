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

/* -- Includes -- */

#include <iostream>
#include <sstream>
#include <ostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>

#define MAX_VERTEX 39

using namespace std;

/* -- Definições de Funções -- */

void printMainVertex (vector<pair<string, string> >);
void printAllVertex (vector<vector<pair<string, string> > >);
void insertVertex(int, string, string, string);
void processLinks();
void insertLinks(string);
void insertLinksOnVertex(int, int, string, string);

/* -- Definições de TADs -- */

vector<vector<pair<string, string> > > ALL_GRAPH(MAX_VERTEX);
vector<string> LINKS;


#endif // HEADERS_HPP_INCLUDED
