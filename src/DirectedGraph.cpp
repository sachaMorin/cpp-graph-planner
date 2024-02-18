//
// Created by sacha on 16/02/24.
//

#include "string"
#include "../include/DirectedGraph.h"

using namespace std;

void DirectedGraph::addNode(Coord p) {
    if (hasNode(p))
        throw GraphException("Node with coordinates " + p.to_string() + " already exists");

    nodeMap[p] = Node(p);
}

void DirectedGraph::addNode(int x, int y) {
    addNode(Coord {x, y});
}

size_t DirectedGraph::size() {
    return nodeMap.size();
}

string NodeErrorMsg(Coord p) {
    return "Trying to add edge connecting node " + p.to_string() + ", which does not exist";
}


void DirectedGraph::addEdge(Coord p1, Coord p2, double cost) {
    if (!hasNode(p1))
        throw GraphException(NodeErrorMsg(p1));
    if (!hasNode(p2))
        throw GraphException(NodeErrorMsg(p2));
    nodeMap[p1].addOutEdge(Edge{p2, cost});
}

void DirectedGraph::addEdge(Coord p1, Coord p2) {
    addEdge(p1, p2, 1.);
}

void DirectedGraph::addEdge(int x1, int y1, int x2, int y2, double cost) {
    addEdge(Coord {x1, y1}, Coord {x2, y2}, cost);
}

void DirectedGraph::addEdge(int x1, int y1, int x2, int y2) {
    addEdge(Coord {x1, y1}, Coord {x2, y2}, 1.);
}

bool DirectedGraph::hasNode(Coord p) {
    return nodeMap.count(p) > 0;
}

bool DirectedGraph::hasNode(int x, int y) {
    return hasNode(Coord{x, y});
}

_Rb_tree_iterator<pair<const Coord, Node>> DirectedGraph::begin() {
    return nodeMap.begin();
}

_Rb_tree_iterator<pair<const Coord, Node>> DirectedGraph::end() {
    return nodeMap.end();
}

size_t DirectedGraph::nEdges() {
    size_t result = 0;
    for(auto &[coord, node]: *this)
        result += node.degreeOut();
    return result;
}

void DirectedGraph::printNodesDegrees() {
    for (auto& [coord, node]: *this)
        cout << coord.to_string() << ": " << node.degreeOut() << endl;
}


GraphException::GraphException(const string &msg) : msg(msg) {}

const char *GraphException::what() const noexcept {
    return msg.c_str();
}
