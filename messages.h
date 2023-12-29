/**
 * @file
*/

#include <string>
#include <map>
#include <set>
#include <vector>

#ifndef MESSAGES_H
#define MESSAGES_H

typedef std::map<std::string, std::set<std::string> > Graph ;
typedef std::vector<std::pair<std::pair<std::string, std::string>, double > > Data ;

/** Wypisuje na standardowe wyjscie uzycie przełącznikow */
void help() ;

void no_arguments() ;

void fileopen_error() ;

void no_input() ;

void no_output() ;

void no_reliability() ;

/** Wypisuje na standardowe wyjście zawartość mapy reprezentującą graf
 * @param graph graf do wyświetlenia */
void show_graph(const Graph & graph) ;

void show_data(const Data & data) ;

#endif