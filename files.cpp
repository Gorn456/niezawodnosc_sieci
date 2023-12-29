#include "files.h"
#include "messages.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//Connections readfile(const std::string &path) {
//    Connections connections ;
//    std::ifstream file (path) ;
//
//    if (file) {
//        std::string line ;
//        std::string temp ;
//        while (getline(file, line))
//        {
//            std::vector<std::string> computers_in_line ;
//            std::stringstream ss (line) ;
//            for (int i = 0; i < 2; i++) {
//                ss >> temp ;
//                computers_in_line.push_back(temp) ;
//                }
//            connections.Computers.push_back(computers_in_line) ;
//            ss >> temp ;
//            connections.Costs.push_back(stod(temp)) ;
//
//        }
//
//    }
//    else
//        fileopen_error() ;
//
//    return connections ;
//
//}

Graph create_graph (const std::string & path) {
    Graph graph ;
    std::ifstream file (path) ;

    if (file) {
        std::string line ;
        std::string node1, node2 ;
        double length ;
        while (std::getline(file, line)) {
            std::stringstream sos (line) ;
            if (!(sos >> node1)) continue ;
            if (!(sos >> node2)) continue ;

            graph[node1].insert(node2) ;
            graph[node2].insert(node1) ;
            if ((sos >> length)) continue ;

//            graph[node1].insert({node2, length}) ;
//            graph[node2].insert({node1, length}) ;
        }
        file.close() ;
    }
    else
        fileopen_error() ;

    return graph ;

}

Data readfile(const std::string & path) {
    Data data ;
    std::ifstream file (path) ;

    if (file) {
        std::string line;
        std::string node1, node2;
        double length;
        std::pair<std::pair<std::string, std::string>, double> temp;
        while (std::getline(file, line)) {
            std::stringstream sos(line);
            if (!(sos >> node1)) continue;
            if (!(sos >> node2)) continue;
            if (!(sos >> length)) continue;

            temp.first.first = node1;
            temp.first.second = node2;
            temp.second = length;
            data.push_back(temp);
        }
        file.close() ;
    }
    else
        fileopen_error() ;

    return data ;
}

