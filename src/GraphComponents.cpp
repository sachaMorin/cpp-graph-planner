//
// Created by sacha on 15/02/24.
//
#include "../include/DirectedGraph.h"
#include <string>

using namespace std;

Node::Node() = default;

Node::Node(Coord p) : nodeCoord(p) {
}

Node::Node(int x, int y) : nodeCoord(Coord {x, y}) {
}

void Node::addOutEdge(Edge e) {
    outEdges.insert(e);
}

size_t Node::degreeOut() const {
    return outEdges.size();
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


ostream &Coord::operator<<(ostream &out) const {
    return out << Coord::to_string();
}

string Coord::to_string() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

string NodeErrorMsg(Coord p) {
    return "Trying to add edge connecting node " + p.to_string() + ", which does not exist";
}

GraphException::GraphException(const string &msg) : msg(msg) {}

const char *GraphException::what() const noexcept {
    return msg.c_str();
}