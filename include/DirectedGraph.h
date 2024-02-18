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

    bool hasNode(Coord p);
    bool hasNode(int x, int y);

    virtual void addEdge(Coord p1, Coord p2, double cost);
    void addEdge(Coord p1, Coord p2);
    void addEdge(int x1, int y1, int x2, int y2, double cost);
    void addEdge(int x1, int y1, int x2, int y2);

    virtual size_t nEdges();
    size_t size();
    void printNodesDegrees();

    _Rb_tree_iterator<pair<const Coord, Node>> begin();
    _Rb_tree_iterator<pair<const Coord, Node>> end();
protected:
   map<Coord, Node> nodeMap;
};

string NodeErrorMsg(Coord p);


struct GraphException : exception {
    string msg;
    explicit GraphException(const string& msg);
    const char* what() const noexcept;
};

#endif //CPP_PLANNER_DIRECTEDGRAPH_H
