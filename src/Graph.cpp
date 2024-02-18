//
// Created by sacha on 16/02/24.
//

#include "string"
#include "../include/Graph.h"

using namespace std;

void Graph::addNode(Coord p) {
    if (hasNode(p))
        throw GraphException("Node with coordinates " + p.to_string() + " already exists");

    nodeMap[p] = Node(p);
}

void Graph::addNode(int x, int y) {
    addNode(Coord {x, y});
}

size_t Graph::size() {
    return nodeMap.size();
}

string NodeErrorMsg(Coord p) {
    return "Trying to add edge connecting node " + p.to_string() + ", which does not exist";
}

void Graph::addEdge(Coord p1, Coord p2, double cost) {
    if (!hasNode(p1))
        throw GraphException(NodeErrorMsg(p1));
    if (!hasNode(p2))
        throw GraphException(NodeErrorMsg(p2));
    nodeMap[p1].addOutEdge(Edge{p2, cost});
}

void Graph::addEdge(int x1, int y1, int x2, int y2, double cost) {
    addEdge(Coord {x1, y1}, Coord {x2, y2}, cost);
}

void Graph::addUndirectedEdge(Coord p1, Coord p2, double cost) {
    if (!hasNode(p1))
        throw GraphException(NodeErrorMsg(p1));
    if (!hasNode(p2))
        throw GraphException(NodeErrorMsg(p2));
    nodeMap[p1].addOutEdge(Edge{p2, cost});
    nodeMap[p2].addOutEdge(Edge{p1, cost});
}

void Graph::addUndirectedEdge(int x1, int y1, int x2, int y2, double cost) {
    addUndirectedEdge(Coord {x1, y1}, Coord {x2, y2}, cost);
}

bool Graph::hasNode(Coord p) {
    return nodeMap.count(p) > 0;
}

bool Graph::hasNode(int x, int y) {
    return hasNode(Coord{x, y});
}

_Rb_tree_iterator<pair<const Coord, Node>> Graph::begin() {
    return nodeMap.begin();
}

_Rb_tree_iterator<pair<const Coord, Node>> Graph::end() {
    return nodeMap.end();
}


GraphException::GraphException(const string &msg) : msg(msg) {}

const char *GraphException::what() const noexcept {
    return msg.c_str();
}
