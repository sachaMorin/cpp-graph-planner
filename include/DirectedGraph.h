//
// Created by sacha on 16/02/24.
//

#ifndef CPP_PLANNER_DIRECTEDGRAPH_H
#define CPP_PLANNER_DIRECTEDGRAPH_H

#include <map>
#include "GraphComponents.h"

using namespace std;

class DirectedGraph {
public:
    void addNode(Coord p);

    void addNode(int x, int y);

    bool hasNode(Coord p) const;

    bool hasNode(int x, int y) const;

    virtual void addEdge(Coord p1, Coord p2, double cost);

    void addEdge(Coord p1, Coord p2);

    void addEdge(int x1, int y1, int x2, int y2, double cost);

    void addEdge(int x1, int y1, int x2, int y2);

    size_t size();

    virtual size_t nEdges() const;

    void printNodesDegrees() const;

    map<Coord, Node>::iterator begin();

    map<Coord, Node>::iterator end();

    map<Coord, Node>::const_iterator begin() const;

    map<Coord, Node>::const_iterator end() const;

protected:
    map<Coord, Node> nodeMap;
};


#endif //CPP_PLANNER_DIRECTEDGRAPH_H
