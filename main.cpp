#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "messages.h"
#include "files.h"

int main(int argc, char* argv[]) {
    
 //   std::cout << "Liczba argumentow: " << argc << std::endl ;

    bool input, output, reliability;
    Graph graf ;
    Graph final ;
    Data dane ;
    int reliability_level ;
    int min_connections ;
    double max_cost = 0 ;
    if (argc == 1) {
        no_arguments() ;
        return 0 ;
    }
    else {
        for (int j = 0; j < argc; j++) { // sprawdzenie czy uzyto odpowienich przelacznikow
        std::string argument = argv[j] ;
        if (argument == "-i") input = true ;
        else if (argument == "-o") output = true ;
        else if (argument == "-n") reliability = true ;
        if (argument == "-h" || argument == "--help") {help() ; return 0; }
    }
        if (input && output && reliability) { // input && output && reliability
            for (int i = 1; i < argc; i++) { // przejscie po argumentach
                std::string argument = argv[i] ;

                if (argument == "-i") {
                    std::string path = argv[i + 1] ;
                    graf = create_graph(path) ;
                    dane = readfile(path) ;
                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wejściowego
                }
                else if (argument == "-o") {
                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wyjściowego
                }
                else if (argument == "-n") {
                    reliability_level = std::stod(argv[i + 1]) ;
                }
                
            }
        }
        else {
            if (not input) {
                no_input() ;
            }
             if (not output) {
                no_output() ;
            }
             if (not reliability) {
                 no_reliability() ;
             }
        } 
    }
    show_graph(graf) ;
    std::cout << std::endl ;
    show_data(dane) ;

    std::sort(dane.begin(), dane.end(), [](const auto &a, const auto &b){ return a.second > b.second;}) ;
    std::cout << "-----------------------" << std::endl ;
    show_data(dane) ;
    min_connections = reliability_level + 1 ;

    for (const auto & node : graf) {
        double cost = 0 ;
        std::string pierwszy = node.first ;
        Graph result = graf ;
        for (const auto & connection : dane) {
            std::string node1 = connection.first.first ;
            std::string node2 = connection.first.second ;
            if ((node1 == pierwszy or node2 == pierwszy) and result[pierwszy].size() > min_connections ) {
                cost += connection.second ;
                result[node1].erase(node2) ;
                result[node2].erase(node1) ;
            }
        }
            for (const auto connection : dane) {
                std::string node1 = connection.first.first ;
                std::string node2 = connection.first.second ;
                if (result[node1].size() > min_connections and result[node2].size() > min_connections ) {
                    cost += connection.second ;
                    result[node1].erase(node2) ;
                    result[node2].erase(node1) ;
                }
            }
        if (cost >= max_cost) {
            max_cost = cost ;
            final = result ;
        }


    }

//    for (const auto connection : dane) {
//        std::string node1 = connection.first.first ;
//        std::string node2 = connection.first.second ;
//        if (graf[node1].size() > min_connections and graf[node2].size() > min_connections ) {
//            graf[node1].erase(node2) ;
//            graf[node2].erase(node1) ;
//        }
//    }

    show_graph(final) ;


    return 0 ;
}