//
// Created by sacha on 18/02/24.
//

#include "../include/UndirectedGraph.h"

void UndirectedGraph::addEdge(Coord p1, Coord p2, double cost) {
    if (!hasNode(p1))
        throw GraphException(NodeErrorMsg(p1));
    if (!hasNode(p2))
        throw GraphException(NodeErrorMsg(p2));
    nodeMap[p1].addOutEdge(Edge{p2, cost});
    nodeMap[p2].addOutEdge(Edge{p1, cost});
}

void UndirectedGraph::addEdge(Coord p1, Coord p2) {
    DirectedGraph::addEdge(p1, p2);
}

void UndirectedGraph::addEdge(int x1, int y1, int x2, int y2, double cost) {
    DirectedGraph::addEdge(x1, y1, x2, y2, cost);
}

void UndirectedGraph::addEdge(int x1, int y1, int x2, int y2) {
    DirectedGraph::addEdge(x1, y1, x2, y2);
}
