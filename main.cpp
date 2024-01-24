#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "messages.h"
#include "files.h"

int main(int argc, char* argv[]) {

    bool input, output, reliability;
    std::string output_path ;
    Graph graf ;
    Data dane ;
    int reliability_level ;
    int min_connections ;
    double max_cost = 0 ;

    if (argc == 1) {
        no_arguments() ;
        return 0 ;
    }
    else {
        for (int j = 0; j < argc; j++) {
        std::string argument = argv[j] ;
        if (argument == "-i") input = true ;
        else if (argument == "-o") output = true ;
        else if (argument == "-n") reliability = true ;
        if (argument == "-h" || argument == "--help") {help() ; return 0; }
    }
        if (input && output && reliability) { 
            for (int i = 1; i < argc; i++) {
                std::string argument = argv[i] ;

                if (argument == "-i") {
                    std::string path = argv[i + 1] ;
                    dane = readfile(path) ;
                    i++ ;
                }
                else if (argument == "-o") {
                    output_path = argv[i + 1] ;
                    i++ ;
                }
                else if (argument == "-n") {
                    reliability_level = std::stoi(argv[i + 1]) ;
                    if (reliability_level < 0) {negative_reliability() ; return 0 ; } 
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

   
    graf = create_graph(dane) ;
    auto it = graf.begin() ;
    if (Bfs(graf, it->first).size() != graf.size()) {
        inconsistent_graph() ; return 0 ;
    }

    std::sort(dane.begin(), dane.end(), [](const auto &a, const auto &b){ return a.second > b.second;}) ;

    Graph result_graph = reverse_kruskal(dane, reliability_level + 1, graf) ;
    writefile(output_path, result_graph) ;

   
    return 0 ;
}