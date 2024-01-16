/**
 * @file
*/
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

#ifndef FILES_H
#define FILES_H

typedef std::map<std::string, std::set<std::string> > Graph ;
typedef std::vector<std::pair<std::pair<std::string, std::string>, double > > Data ;

Data readfile(const std::string & path) ;

Graph create_graph(const Data & data) ;

Graph reverse_kruskal(const Data & data, const int min_connections, const Graph & graph) ;

void writefile(const std::string & path, Graph & graph) ;

#endif