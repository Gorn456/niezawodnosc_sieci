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

/**
 * @brief  wczytuje graf z pliku
 * @param path ściezka do pliku
 * @return strukturę danych reprezentująca graf
*/
Graph create_graph(const std::string & path) ;

Data readfile(const std::string & path) ;

void writefile(const std::string & path, Graph & graph) ;

#endif