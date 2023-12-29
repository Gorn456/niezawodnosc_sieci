/**
 * @file
*/
#include <vector>
#include <string>
#include <map>
#include <set>

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


///**
// * @brief Struktura reprezentująca jedno połączenia między miastami wraz z ich kosztem.
// */
//struct Connections {
//    std::vector<std::vector<std::string> > Computers ;
//    std::vector<double> Costs ;
//
//} ;
//
///**
// * @brief  wczytuje dane z pliku
// * @param path ściezka do pliku
// * @return Strukturę Connections uzupełnioną wartościami z pliku
//*/
//Connections readfile(const std::string &path) ;
#endif