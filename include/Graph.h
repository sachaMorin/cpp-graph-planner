//
// Created by sacha on 16/02/24.
//

#ifndef CPP_PLANNER_GRAPH_H
#define CPP_PLANNER_GRAPH_H

#include <map>
#include "GraphComponents.h"

using namespace std;

class Graph {
public:
    void addNode(Coord p);
    void addNode(int x, int y);
    bool hasNode(Coord p);
    bool hasNode(int x, int y);
    void addEdge(Coord p1, Coord p2, double cost = 1.);
    void addEdge(int x1, int y1, int x2, int y2, double cost = 1.);
    void addUndirectedEdge(Coord p1, Coord p2, double cost = 1.);
    void addUndirectedEdge(int x1, int y1, int x2, int y2, double cost = 1.);
    size_t size();
    _Rb_tree_iterator<pair<const Coord, Node>> begin();
    _Rb_tree_iterator<pair<const Coord, Node>> end();
private:
   map<Coord, Node> nodeMap;
};


struct GraphException : exception {
    string msg;
    explicit GraphException(const string& msg);
    const char* what() const noexcept;
};

#endif //CPP_PLANNER_GRAPH_H
