//
// Created by sacha on 15/02/24.
//

#ifndef CPP_PLANNER_GRAPHCOMPONENTS_H
#define CPP_PLANNER_GRAPHCOMPONENTS_H

#include <map>
#include <iostream>
#include <set>
#include <string>

using namespace std;

// 2D Coordinate
struct Coord {
    int x;
    int y;

    ostream &operator<<(ostream &out) const;

    string to_string() const;
};

bool operator<(Coord a, Coord b);

// Graph Edge
struct Edge {
    Coord to;
    double cost = 1.;
};

bool operator<(Edge a, Edge b);

// Graph Node
class Node {
public:
    explicit Node();

    explicit Node(Coord p);

    explicit Node(int x, int y);

    void addOutEdge(Edge e);

    size_t degreeOut() const;

    set<Edge>::iterator begin();

    set<Edge>::iterator end();

    set<Edge>::const_iterator begin() const;

    set<Edge>::const_iterator end() const;

private:
    Coord nodeCoord;
    set<Edge> outEdges{};
};

// Error handling
struct GraphException : exception {
    string msg;

    explicit GraphException(const string &msg);

    const char *what() const noexcept;
};


string NodeErrorMsg(Coord p);

#endif //CPP_PLANNER_GRAPHCOMPONENTS_H
