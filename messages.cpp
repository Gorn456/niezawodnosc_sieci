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
            << "Error:" << RESET_TEXT << "use -o <path_to_output_file>" << std::endl ;
}
