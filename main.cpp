#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "messages.h"
#include "files.h"

int main(int argc, char* argv[]) {
    
 //   std::cout << "Liczba argumentow: " << argc << std::endl ;

    // const int array_size = 10e4 ;
    // std::string Connections[array_size][2] = {} ;
    // double Cost_of_connections[array_size / 2] = {} ;

    bool input, output, reliability;

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
        if (input && output) { // input && output && reliability
            for (int i = 1; i < argc; i++) { // przejscie po argumentach
                std::string argument = argv[i] ;

                if (argument == "-i") {
                    std::string path = argv[i + 1] ;
                    Connections file = readfile(path) ;
                    
                    auto komputery = file.Computers ;
                    auto koszty = file.Costs ;

                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wejściowego
                }
                else if (argument == "-o") {
                    // std::string path = argv[i + 1] ;
                    // std::ofstream file (path) ;
                    // if (file) {
                    //     for (int i = 0; i < 6; i++) {
                    //         for (int j = 0; j < 2; j++) {
                    //             file << Connections[i][j] << " " ;
                    //         }
                    //         file << Cost_of_connections[i] << " " ;
                    //         file << '\n' ;
                    //     }
                    // }
                    // else
                    //     fileopen_error() ;

                    // file.close() ;
                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wyjściowego
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
        } 
    }
    // for (int i = 0; i < 6; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         std::cout << Connections[i][j] << " " ;
    //     }
    //     std::cout << Cost_of_connections[i] << " " ;
    //     std::cout << std::endl ;
    // }
    // return 0 ;

    // for (int i = 0; i < argc; i++) {
    //     std::cout << argv[i] << std::endl ;

    // }
}