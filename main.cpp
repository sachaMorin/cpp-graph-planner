#include <iostream>
#include <vector>
#include "include/UndirectedGraph.h"

using namespace std;

int main() {
    UndirectedGraph g;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            g.addNode(i, j);


    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++) {
            g.addEdge(i, j, i - 1, j);
            g.addEdge(i, j, i, j - 1);
            g.addEdge(i, j, i + 1, j);
            g.addEdge(i, j, i, j + 1);
        }

    cout << g.nEdges() << endl;
    g.printNodesDegrees();


    return 0;
}
