//
// Created by sacha on 25/02/24.
//

#ifndef CPP_PLANNER_GRIDGRAPH_H
#define CPP_PLANNER_GRIDGRAPH_H

#include "UndirectedGraph.h"


class GridGraph: public UndirectedGraph {
public:
    GridGraph(int width, int height);
private:
    int width;
    int height;
};


#endif //CPP_PLANNER_GRIDGRAPH_H
