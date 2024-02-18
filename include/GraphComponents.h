//
// Created by sacha on 15/02/24.
//

#ifndef CPP_PLANNER_GRAPHCOMPONENTS_H
#define CPP_PLANNER_GRAPHCOMPONENTS_H

#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Coord {
    int x;
    int y;
    ostream& operator<<(ostream &out);
    string to_string() const;
};

bool operator<(Coord a, Coord b);

struct Edge {
    Coord to;
    double cost = 1.;
};

bool operator<(Edge a, Edge b);

class Node {
    Coord nodeCoord;
    std::set<Edge> outEdges {};
public:
    explicit Node();
    explicit Node(Coord p);
    explicit Node(int x, int y);
    void addOutEdge(Edge e);
    size_t degreeOut();
};



#endif //CPP_PLANNER_GRAPHCOMPONENTS_H
