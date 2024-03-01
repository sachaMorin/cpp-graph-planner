//
// Created by sacha on 27/02/24.
//
#include <stdio.h>
#include "include/OccupancyGraph.h"

using namespace cv;


int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: occupancy-planner.out <PGM>\n");
        return -1;
    }

    int xStart = 1;
    int yStart = 1;
    int xGoal = 99;
    int yGoal = 99;

    OccupancyGraph graph = OccupancyGraph (argv[1], true);

    // Dijkstra (no heuristic)
    auto pathDijkstra = graph.aStar(xStart, yStart, xGoal, yGoal, NONE);
    cout << "Dijkstra Cost         : "  <<  pathDijkstra.cost  << "\n";
    cout << "Dijkstra Visited      : "  <<  (double) graph.nVisited() / (double) graph.size()  << "\n";
    graph.saveImage("map_dijkstra.png");

    // A* (TaxiCab)
    auto pathTaxi = graph.aStar(xStart, yStart, xGoal, yGoal, TAXICAB);
    cout << "A* (Taxicab) Cost     : "  <<  pathTaxi.cost  << "\n";
    cout << "A* (Taxicab) Visited  : "  <<  (double) graph.nVisited() / (double) graph.size()  << "\n";
    graph.saveImage("map_taxi.png");

    // A* (Euclidean)
    auto pathEuclidean = graph.aStar(xStart, yStart, xGoal, yGoal, EUCLIDEAN);
    cout << "A* (Euclidean) Cost   : "  <<  pathEuclidean.cost  << "\n";
    cout << "A* (Euclidean) Visited: "  <<  (double) graph.nVisited() / (double) graph.size()  << "\n";
    graph.saveImage("map_euclidean.png");
    return 0;
}
