//
// Created by sacha on 18/02/24.
//

#ifndef CPP_PLANNER_UNDIRECTEDGRAPH_H
#define CPP_PLANNER_UNDIRECTEDGRAPH_H

#include "../include/DirectedGraph.h"

class UndirectedGraph : public DirectedGraph {
public:
    void addEdge(Coord p1, Coord p2, double cost) override;
    virtual void addEdge(Coord p1, Coord p2);
    virtual void addEdge(int x1, int y1, int x2, int y2, double cost);
    virtual void addEdge(int x1, int y1, int x2, int y2);
};


#endif //CPP_PLANNER_UNDIRECTEDGRAPH_H
