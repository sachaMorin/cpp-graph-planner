#include <iostream>
#include <cmath>
#include "include/GridGraph.h"

using namespace std;


int main() {
    GridGraph g = GridGraph(100, 100);

    int xGoal = 99, yGoal  = 99;

    auto pathL2 = g.aStar(0, 0, xGoal, yGoal);
    cout << "Nodes visited by A* (Euclidean) : " << g.nVisited() << "\n";

    auto pathL1 = g.aStar(0, 0, xGoal, yGoal, [] (Coord a, Coord b) {return abs(a.x - b.x) + abs(a.y - b.y);});
    cout << "Nodes visited by A* (TaxiCab)   : " << g.nVisited() << "\n";

    auto pathDijkstra = g.aStar(0, 0, xGoal, yGoal, [] (Coord a, Coord b) {return 0;});
    cout << "Nodes visited by Dijkstra       : " << g.nVisited() << "\n";


    return 0;
}
