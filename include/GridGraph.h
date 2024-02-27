//
// Created by sacha on 25/02/24.
//

#ifndef CPP_PLANNER_GRIDGRAPH_H
#define CPP_PLANNER_GRIDGRAPH_H

#include "UndirectedGraph.h"


class GridGraph: public UndirectedGraph {
public:
    GridGraph(int width, int height, bool eightWay = false);
private:
    int width;
    int height;
    bool eightWay;
};


#endif //CPP_PLANNER_GRIDGRAPH_H
