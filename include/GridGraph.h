//
// Created by sacha on 25/02/24.
//

#ifndef CPP_PLANNER_GRIDGRAPH_H
#define CPP_PLANNER_GRIDGRAPH_H

#include "UndirectedGraph.h"


class GridGraph: public UndirectedGraph {
public:
    GridGraph(int width, int height, bool eightWayConn = false);
    void buildGraph();
protected:
    int width;
    int height;
    bool eightWay;

    virtual void createNodes();
    void createEdges();
};


#endif //CPP_PLANNER_GRIDGRAPH_H
