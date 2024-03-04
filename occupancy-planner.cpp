//
// Created by sacha on 27/02/24.
//
#include <cstdio>
#include <cstdlib>
#include "OccupancyGraph.h"

using namespace std;
using namespace cv;


int main(int argc, char **argv) {
    if (argc != 7) {
        printf("usage: ./occupancy-planner <PGM FILE> <OUTPUT DIR> <xStart> <yStart> <xGoal> <yGoal>\n");
        return -1;
    }

    string mapPath = argv[1];
    string outputPath = argv[2];

    int xStart = stoi(argv[3]);
    int yStart = stoi(argv[4]);
    int xGoal = stoi(argv[5]);
    int yGoal = stoi(argv[6]);

    OccupancyGraph graph = OccupancyGraph(argv[1], true);
    cout << "Building graph..." << "\n";
    graph.buildGraph();

    cout << "Running search with 3 heuristics..." << "\n\n";
    // Dijkstra (no heuristic)
    auto pathDijkstra = graph.aStar(xStart, yStart, xGoal, yGoal, NONE);
    cout << "Dijkstra Cost         : " << pathDijkstra.cost << "\n";
    cout << "Dijkstra Visited      : " << (double) graph.nVisited() / (double) graph.size() << "\n";
    graph.saveImage(outputPath + "/map_dijkstra.png");

    // A* (TaxiCab)
    auto pathTaxi = graph.aStar(xStart, yStart, xGoal, yGoal, TAXICAB);
    cout << "A* (Taxicab) Cost     : " << pathTaxi.cost << "\n";
    cout << "A* (Taxicab) Visited  : " << (double) graph.nVisited() / (double) graph.size() << "\n";
    graph.saveImage(outputPath + "/map_taxi.png");

    // A* (Euclidean)
    auto pathEuclidean = graph.aStar(xStart, yStart, xGoal, yGoal, EUCLIDEAN);
    cout << "A* (Euclidean) Cost   : " << pathEuclidean.cost << "\n";
    cout << "A* (Euclidean) Visited: " << (double) graph.nVisited() / (double) graph.size() << "\n";
    graph.saveImage(outputPath + "/map_euclidean.png");
    return 0;
}
