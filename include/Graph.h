//
// Created by sacha on 16/02/24.
//

#ifndef CPP_PLANNER_GRAPH_H
#define CPP_PLANNER_GRAPH_H

#include <map>
#include "Node.h"

using namespace std;

class Graph {
public:
    void addNode(Coord p);
    void addNode(int x, int y);
    void addEdge(Coord p1, Coord p2, double cost = 1.);
    void addEdge(int x1, int y1, int x2, int y2, double cost = 1.);
    size_t size();
private:
   map<Coord, Node> nodeMap;
};


#endif //CPP_PLANNER_GRAPH_H
