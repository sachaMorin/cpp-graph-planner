#include <iostream>
#include <vector>
#include "include/GridGraph.h"

using namespace std;

int main() {
    GridGraph g = GridGraph(100, 100);

    cout << g.size() << " nodes" << "\n";
    cout << g.nEdges() << " edges" << "\n";

    auto path = g.aStar(0, 0, 0, 99);
    cout << path.size();

    for(auto& coord : path) {
        cout << coord.to_string() << "\n";
    }


    return 0;
}
