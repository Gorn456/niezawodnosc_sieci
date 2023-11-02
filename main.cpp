#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

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

int main(int argc, char* argv[]) {
    
 //   std::cout << "Liczba argumentow: " << argc << std::endl ;
    const int array_size = 10e4 ;
    std::string Connections[array_size][2] = {} ;
    double Cost_of_connections[array_size / 2] = {} ;

    bool input, output, reliability;

    if (argc == 1) {
        std::cout << RED_TEXT << std::setw(10) << std::left
        << "Error:" << RESET_TEXT <<"No arguments! Type -h or --help for help" << std::endl ;
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
                    std::ifstream file (path) ;
                    if (file) {
                        int word_counter = 1, temp_counter = 0, 
                        temp_counter_cost = 0, connections_counter = 0 ;
                        std::string word ;
                        while (file >> word)
                        {
                            if (word_counter % 3 != 0) {
                                switch (temp_counter)
                                {
                                case 0:
                                    Connections[connections_counter][0] =  word;
                                    temp_counter++ ;                           
                                    break;
                                case 1:
                                    Connections[connections_counter][1] =  word;
                                    temp_counter = 0 ; connections_counter++ ;
                                    break;
                                }

                            }
                            else {
                                Cost_of_connections[temp_counter_cost] = std::stod(word) ;
                                temp_counter_cost++ ;
                            }
                            word_counter++ ;
                        }


                    }
                    else
                        std::cout << RED_TEXT << std::setw(10) << std::left
                        << "Error:" << RESET_TEXT << "Can't open file" << std::endl ;

                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wejściowego
                }
                else if (argument == "-o") {
                    std::string path = argv[i + 1] ;
                    std::ofstream file (path) ;
                    if (file) {
                        for (int i = 0; i < 6; i++) {
                            for (int j = 0; j < 2; j++) {
                                file << Connections[i][j] << " " ;
                            }
                            file << Cost_of_connections[i] << " " ;
                            file << '\n' ;
                        }
                    }
                    else {
                        std::cout << RED_TEXT << std::setw(10) << std::left
                        << "Error:" << RESET_TEXT << "Can't open output file" << std::endl ;
                    }
                    file.close() ;
                    i++ ; // pominięcie iteracji argumentu z ściezką pliku wyjściowego
                }
                
            }
        }
        else {
            if (not input) {
                std::cout << RED_TEXT << std::setw(10) << std::left
                        << "Error:" << RESET_TEXT << "use -i <path_to_source_file>" << std::endl ;
            }
             if (not output) {
                std::cout << RED_TEXT << std::setw(10) << std::left
                        << "Error:" << RESET_TEXT << "use -o <path_to_output_file>" << std::endl ;
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