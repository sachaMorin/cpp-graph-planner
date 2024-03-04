//
// Created by sacha on 25/02/24.
//

#include <vector>
#include <cmath>
#include "GridGraph.h"

GridGraph::GridGraph(int width, int height, bool eightWayConn) : width(width), height(height), eightWay(eightWayConn) {
}

void GridGraph::buildGraph() {
    createNodes();
    createEdges();
}

void GridGraph::createNodes() {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            this->addNode(i, j);

}

void GridGraph::createEdges() {
    for (const auto &[nodeFrom, _]: *this) {
        int x = nodeFrom.x, y = nodeFrom.y;
        std::vector<Edge> coords;
        coords.push_back(Edge{x + 1, y, 1.}); // North
        coords.push_back(Edge{x, y + 1, 1.}); // East
        coords.push_back(Edge{x - 1, y, 1.}); // South
        coords.push_back(Edge{x, y - 1, 1.}); // West
        if (eightWay) {
            double sqrt2 = sqrt(2);
            coords.push_back(Edge{x + 1, y + 1, sqrt2}); // North East
            coords.push_back(Edge{x - 1, y + 1, sqrt2}); // South East
            coords.push_back(Edge{x - 1, y - 1, sqrt2}); // South West
            coords.push_back(Edge{x + 1, y - 1, sqrt2}); // North East
        }
        for (const auto &edge: coords)
            if (this->hasNode(edge.to))
                this->addEdge(nodeFrom, edge.to, edge.cost);

    }
}
