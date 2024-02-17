//
// Created by sacha on 15/02/24.
//

#ifndef CPP_PLANNER_NODE_H
#define CPP_PLANNER_NODE_H

#include <vector>
#include <string>

using namespace std;

struct Coord {
    int x;
    int y;
};

bool operator<(Coord a, Coord b);

struct Edge {
    Coord to;
    double cost = 1.;
};

class Node {
    Coord nodeCoord;
    std::vector<Edge> outEdges {};
public:
    explicit Node();
    explicit Node(Coord p);
    explicit Node(int x, int y);
    void addOutEdge(Edge e);
};



#endif //CPP_PLANNER_NODE_H
