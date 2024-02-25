#include <iostream>
#include <vector>
#include "include/GridGraph.h"

using namespace std;

int main() {
    GridGraph g = GridGraph(10, 10);

    cout << g.size() << " nodes" << "\n";
    cout << g.nEdges() << " edges" << "\n";

    g.aStar(5, 5, 1, 1);
//    g.printNodesDegrees();


    return 0;
}
