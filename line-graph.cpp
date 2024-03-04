#include <iostream>
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

using namespace std;


int main() {
    // Build Directed Line Graph on a Diagonal
    cout << "DIRECTED Line Graph" << "\n";
    DirectedGraph dg = DirectedGraph();
    for (int i = 0; i < 10; i++) {
        dg.addNode(i, i);
        if (i > 0)
            dg.addEdge(i - 1, i - 1, i, i);
    }

    cout << "Number of nodes: " << dg.size() << "\n";
    cout << "Number of edges: " << dg.nEdges() << "\n";
    cout << "Node coordinate : Degree" << "\n";
    dg.printNodesDegrees();
    auto directedPath = dg.aStar(4, 4, 0, 0, NONE);
    if (directedPath.path.empty())
        cout << "No path from (4, 4) to (0, 0)" << "\n";

    // Build Undirected Line Graph on a Diagonal
    cout << "\n" << "UNDIRECTED Line Graph" << "\n";
    UndirectedGraph ug = UndirectedGraph();
    for (int i = 0; i < 10; i++) {
        ug.addNode(i, i);
        if (i > 0)
            ug.addEdge(i - 1, i - 1, i, i);
    }

    cout << "Number of nodes: " << ug.size() << "\n";
    cout << "Number of edges: " << ug.nEdges() << "\n";
    cout << "Node coordinate : Degree" << "\n";
    ug.printNodesDegrees();
    auto undirectedPath = ug.aStar(4, 4, 0, 0, NONE);
    cout << "Path from (4, 4) to (0, 0):" << "\n";
    for (const auto &coord: undirectedPath.path)
        cout << coord.toString() << "\n";


    return 0;
}
