#include "messages.h"
#include <iostream>
#include <iomanip>
#define RED_TEXT "\033[1;31m" // Czerwony tekst (pogrubiony)
#define RESET_TEXT "\033[0m" // Zresetuj kolor i styl tekstu
#define BOLD_TEXT "\033[1m" // Pogrubiony tekst

void help() {
    std::cout << BOLD_TEXT << std::setw(10) << std::left << "   -i" << RESET_TEXT
    << "path to source file" << std::endl ;

    std::cout << BOLD_TEXT << std::setw(10) << std::left << "   -o" << RESET_TEXT
    << "path to output file" << std::endl ;

    std::cout << BOLD_TEXT << std::setw(10) << std::left << "   -n" << RESET_TEXT
    << "reliability level (integer)" << std::endl ;
}

void no_arguments() {
    std::cout << RED_TEXT << std::setw(10) << std::left
        << "Error:" << RESET_TEXT <<"No arguments! Type -h or --help for help" << std::endl ;
}

void fileopen_error() {
    std::cout << RED_TEXT << std::setw(10) << std::left
    << "Error:" << RESET_TEXT << "Can't open file" << std::endl ;
}


void no_input() {
    std::cout << RED_TEXT << std::setw(10) << std::left
            << "Error:" << RESET_TEXT << "use -i <path_to_source_file>" << std::endl ;
}

void no_output() {
    std::cout << RED_TEXT << std::setw(10) << std::left
            << "Error:" << RESET_TEXT << "use -n <path_to_output_file>" << std::endl ;
}

void no_reliability() {
    std::cout << RED_TEXT << std::setw(10) << std::left
              << "Error:" << RESET_TEXT << "use -n <reliability level (integer)>" << std::endl ;
}

void show_graph(const Graph & graph) {
    for (const auto & rekord : graph) {
        std::cout << rekord.first << " : " ;
        for (const auto & sasiad : rekord.second) {
            std::cout << "{ " << sasiad << " }" ;
        }
        std::cout << std::endl ;
    }
}

void show_data(const Data & data) {
    for (const auto & rekord : data) {
        std::cout << rekord.first.first << ", " << rekord.first.second << ", " << rekord.second << std::endl ;
    }
}
