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

//    OccupancyGraph graph {argv[1]};
    OccupancyGraph graph = OccupancyGraph (argv[1]);
    cout << graph.size();
    graph.aStar(1, 1, 100, 100, [] (Coord a, Coord b) {return 0;});
    graph.saveImage("map_astar.png");
    return 0;
}
