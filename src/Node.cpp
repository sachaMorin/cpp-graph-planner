//
// Created by sacha on 15/02/24.
//

#include "../include/Node.h"

using namespace std;

Node::Node() = default;

Node::Node(Coord p) : nodeCoord(p) {
}

Node::Node(int x, int y) : nodeCoord(Coord {x, y}) {
}

void Node::addOutEdge(Edge e) {
    outEdges.insert(e);
}

bool operator<(Coord a, Coord b) {
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

bool operator<(Edge a, Edge b) {
    return a.to < b.to;
}


