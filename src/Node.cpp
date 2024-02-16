//
// Created by sacha on 15/02/24.
//

#include "../include/Node.h"

Node::Node() = default;

Node::Node(Coord p) : nodeCoord(p) {
}

Node::Node(int x, int y) : nodeCoord(Coord {x, y}) {
}

void Node::addOutgoingEdge(Edge e) {
    edges.push_back(e);
}

bool operator<(Coord a, Coord b) {
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}
