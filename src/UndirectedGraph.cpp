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