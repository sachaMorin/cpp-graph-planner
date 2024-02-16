//
// Created by sacha on 16/02/24.
//

#include "../include/Graph.h"

void Graph::addNode(Coord p) {
    nodeMap[p] = Node(p);
}

void Graph::addNode(int x, int y) {
    Coord p {x, y};
    nodeMap[p] = Node(p);
}

size_t Graph::size() {
    return nodeMap.size();
}

void Graph::addEdge(Coord p1, Coord p2, double cost) {
    nodeMap[p1].addOutgoingEdge(Edge {p2, cost});
}

void Graph::addEdge(int x1, int y1, int x2, int y2, double cost) {
    Coord p1 {x1, y1};
    Coord p2 {x2, y2};
# HERE

}
