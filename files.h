/**
 * @file
 * @author Kamil Kasperek
 * @date 18.01.2023r.
*/
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

#ifndef FILES_H
#define FILES_H

/** @typedef Graph
 *  @brief mapa, w ktorej klucze są napisami reprezentującymi dany wierzchołek,
 *  wartości to sety napisow, reprezentujące wierzchołki z ktorymi polaczony jest klucz
*/
typedef std::map<std::string, std::set<std::string> > Graph ;

/** @typedef Data
 *  @brief wektor par, para składa się z kolejnej pary, reprezentującej krawędź, druga
 * wartość zewnętrzej pary to waga krawędzi
*/
typedef std::vector<std::pair<std::pair<std::string, std::string>, double > > Data ;

/** @brief wczytuje z pliku dane i zapisuje do struktury Data
 *  @param path ściezka do pliku
 *  @return strukture Data 
*/
Data readfile(const std::string & path) ;

/** @brief tworzy reprezentacje grafu, jako mapy
 *  @param data graf w strukturze Data
 *  @return strukture Graph
*/
Graph create_graph(const Data & data) ;

/** @brief algorytm przeszukiwania wszerz
 *  @param graph graf w strukturze Graph
 *  @param node wierzchołek startowy
 *  @return set wierzchołkow odwiedzonych 
*/
std::set<std::string> Bfs(const Graph& graph, const std::string& node) ;

/** @brief zmodyfikowany reverse-delete algorytm
 *  @param data Struktura Data, reprezentująca krawędzie grafu
 *  @param min_connections Żądany poziom niezawodności (unsigned int)
 *  @param graph Struktura Graph, reprezentująca wierzchołki grafu
 *  @return Strukture Graph, reprezentującą wynik
*/
Graph reverse_kruskal(const Data & data, const int min_connections, const Graph & graph) ;

/** @brief Zapis wyniku do pliku wyjściowego
 *  @param path ściezka do pliku wyjściowego
 *  @param graph Struktura Graph, reprezentująca wynik
 * 
*/
void writefile(const std::string & path, Graph & graph) ;

#endif