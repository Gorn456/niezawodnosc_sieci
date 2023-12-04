#include "files.h"
#include "messages.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Connections readfile(const std::string &path) {
    Connections connections ;
    std::ifstream file (path) ;

    if (file) {
        std::string line ;
        std::string temp ;
        while (getline(file, line))
        {
            std::vector<std::string> computers_in_line ;
            std::stringstream ss (line) ;
            for (int i = 0; i < 2; i++) {
                ss >> temp ;
                computers_in_line.push_back(temp) ;
                }
            connections.Computers.push_back(computers_in_line) ;
            ss >> temp ;
            connections.Costs.push_back(stod(temp)) ;

        }
        
    }
    else
        fileopen_error() ;

    return connections ;

}

