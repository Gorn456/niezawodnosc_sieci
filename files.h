/**
 * @file
*/
#include <vector>
#include <string>

#ifndef FILES_H
#define FILES_H
/**
 * @brief Struktura reprezentująca jedno połączenia między miastami wraz z ich kosztem.
 */
struct Connections {
    std::vector<std::vector<std::string> > Computers ;
    std::vector<double> Costs ;

} ;

/**
 * @brief  wczytuje dane z pliku
 * @param path ściezka do pliku
 * @return Strukturę Connections uzupełnioną wartościami z pliku
*/
Connections readfile(const std::string &path) ;
#endif