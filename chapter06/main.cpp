#include <iostream>
#include <string>
#include "graph_implementation.h"

int main()
{
    GraphMatrix<char, std::string> myGraph;
    int i1 = myGraph.insert('A');
    std::cout << i1 << std::endl;
    int i2 = myGraph.insert('B');
    std::cout << i2 << std::endl;
    myGraph.insert('C');
    myGraph.insert('D');
    myGraph.insert('E');
    myGraph.insert('F');
    myGraph.insert("AC", 1, 0, 2);
    myGraph.insert("AD", 1, 0, 3);
    myGraph.insert("BC", 1, 1, 2);
    myGraph.insert("CD", 1, 2, 3);
    myGraph.insert("CE", 1, 2, 4);
    myGraph.insert("CF", 1, 2, 5);
    myGraph.insert("EF", 1, 4, 5);
    for (int i = 0; i < myGraph.n; ++i) {
        for (int j = 0; j < myGraph.n; ++j) {
            std::cout << myGraph.weight(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << myGraph.status(0) << std::endl;
    myGraph.dfs(0);
    std::cout << myGraph.status(0) << std::endl;

    return 0;
}