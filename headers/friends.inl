/** @file friends.inl
 *  @brief File of libraries.
 *
 *  This file includes all general libraries
 *  of C++ as well as the signature of each funcion of the program.
 *  Also, all global variables are kept here.
 *
 *  @author Dayanne Fernandes da Cunha 13/0107191
 *  @bug No bug known.
 */

#ifndef HEADERS_INL_INCLUDED
#define HEADERS_INL_INCLUDED

/* -- Basic libraries for the better functioning of the program -- */

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

/* ----------- Definition of all functions of the program ----------- */

/* -- Functions to show data on command terminal -- */

void printAllVertex (vector<vector<pair<int, pair<string, string> > > >);
void printMainVertex (vector<pair<int, pair<string, string> > >);
void printAllDegress ();
void printAllCliques();
void printClique(vector<int>);

/* -- Functions to create and populate the base graph -- */

void insertVertex(int, string, string);
void insertLinks(string);
void processLinks();
void insertLinksOnVertex(int, int, string, string);

/* -- Functions to count all the degrees of every main vertex -- */

void countDegrees();

/* -- Functions to execute the algorithm of Bron-Kerbosch -- */

vector<int> uni(vector<int>, int);
vector<int> intersec(vector<int>, int);
void bron(vector<int>,vector<int>,vector<int>);
void prepareBron();

/* -- Global variables definitions -- */

#define MAX_VERTEX 39

vector<vector<pair<int, pair<string, string> > > > ALL_GRAPH(MAX_VERTEX);
vector<pair<int, int> > DEGREES(MAX_VERTEX);
set<vector<int> > ALL_CLIQUES;
vector<string> LINKS;

/* -- Function to ordinate the degrees from highest grade to lowest -- */

bool desc(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second > b.second;
}

#endif // HEADERS_INL_INCLUDED
