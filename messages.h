/**
 * @file
 * @author Kamil Kasperek
 * @date 18.01.2023r.
*/

#include <string>
#include <map>
#include <set>
#include <vector>

#ifndef MESSAGES_H
#define MESSAGES_H

typedef std::map<std::string, std::set<std::string> > Graph ;
typedef std::vector<std::pair<std::pair<std::string, std::string>, double > > Data ;

/** @brief Wypisuje na standardowe wyjscie uzycie przełącznikow */
void help() ;

/** @brief Wypisuje na standardowe wyjscie błąd o nie uzyciu przełącznikow */
void no_arguments() ;

/** @brief Wypisuje na standardowe wyjscie informacje o błędzie przy otwarciu pliku */
void fileopen_error() ;

/** @brief Wypisuje na standardowe wyjscie informacje o braku przełącznika -i */
void no_input() ;

/** @brief Wypisuje na standardowe wyjscie informacje o braku przełącznika -o */
void no_output() ;

/** @brief Wypisuje na standardowe wyjscie informacje o braku przełącznika -n */
void no_reliability() ;

/** @brief Wypisuje na standardowe wyjscie informacje o minusowej niezawodnosci */
void negative_reliability() ;

/** @brief Wypisuje na standardowe wyjscie informacje o niespojnym grafie wejściowym */
void inconsistent_graph() ;

/** @brief Wypisuje na standardowe wyjście zawartość mapy reprezentującą graf
 * @param graph graf do wyświetlenia w strukturze Graph */
void show_graph(const Graph & graph) ;

/** @brief Wypisuje na standardowe wyjście dane w postaci vectora par
 * @param data dane zapisane za pomocą struktury Data
*/
void show_data(const Data & data) ;

#endif