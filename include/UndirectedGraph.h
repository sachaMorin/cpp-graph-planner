//
// Created by sacha on 18/02/24.
//

#ifndef CPP_PLANNER_UNDIRECTEDGRAPH_H
#define CPP_PLANNER_UNDIRECTEDGRAPH_H

#include "../include/DirectedGraph.h"


class UndirectedGraph : public DirectedGraph {
public:
    using DirectedGraph::addEdge; // Pull overloads from DirectedGraph
    void addEdge(Coord p1, Coord p2, double cost) override;

    size_t nEdges() const override;
};


#endif //CPP_PLANNER_UNDIRECTEDGRAPH_H
