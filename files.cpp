#include "files.h"
#include "messages.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

// std::set<std::string> Bfs(const Graph& graph, const std::string& node) ;

Data readfile(const std::string & path) {
    Data data ;
    std::ifstream file (path) ;

    if (file) {
        std::string line ;
        std::string node1, node2 ;
        double length ;
        std::pair<std::pair<std::string, std::string>, double> temp ;
        while (std::getline(file, line)) {
            std::stringstream sos(line) ;
            if (!(sos >> node1)) continue ;
            if (!(sos >> node2)) continue ;
            if (!(sos >> length)) continue ;

            temp.first.first = node1 ;
            temp.first.second = node2 ;
            temp.second = length ;
            data.push_back(temp) ;
        }
        file.close() ;
    }
    else
        fileopen_error() ;

    return data ;
}

Graph create_graph(const Data & data) {
    Graph graph ;
    for (const auto & line : data) {
        graph[line.first.first].insert(line.first.second) ;
        graph[line.first.second].insert(line.first.first) ;
    }
    return graph ;
}

Graph reverse_kruskal(const Data & data, const int min_connections, const Graph & graph) {
    double max_cost = 0 ;
    Graph final ;
    if (min_connections == 1) {
        final = graph ;
        auto it = final.begin() ;
        for (const auto & connection : data) {
            std::string node1 = connection.first.first ;
            std::string node2 = connection.first.second ;
            final[node1].erase(node2) ;
            final[node2].erase(node1) ;
            if(Bfs(final, it->first).size() != graph.size()) {
                final[node1].insert(node2) ;
                final[node2].insert(node1) ;
            }
        }
        show_graph(final) ;
        return final ;
    } 
    else {         
    for (const auto & node : graph) {
        double cost = 0 ;
        std::string pierwszy = node.first ;
        Graph result = graph ;
        for (const auto & connection : data) {
            std::string node1 = connection.first.first ;
            std::string node2 = connection.first.second ;
            if ((node1 == pierwszy or node2 == pierwszy) and result[pierwszy].size() > min_connections ) {
                cost += connection.second ;
                result[node1].erase(node2) ;
                result[node2].erase(node1) ;
            }
        }
            for (const auto & connection : data) {
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
    return final ;
    }

}

std::set<std::string> Bfs(const Graph& graph, const std::string& node) {
    if (graph.find(node) == graph.end()) return {} ;
    std::set<std::string> result {node} ;
    std::list<std::string> nodes {node} ;

    while (!nodes.empty()) {
        for (const auto & el : graph.at(nodes.front())) {
            if (result.count(el) == 0) {
                result.insert(el) ;
                nodes.push_back(el) ;
            }
        }
        nodes.pop_front() ;
    }
    return result ;

}

void writefile(const std::string & path, Graph & graph) {
    std::ofstream file (path) ;
    if (file) {
        for (auto & record : graph) {
            std::string first = record.first ;
            if (!(record.second.empty())) {
                for (auto &node: record.second) {
                    file << first << " " << node << std::endl;
                    graph[node].erase(first);
                }
            }
        }
        file.close() ;
    }
    else
        fileopen_error() ;
}
