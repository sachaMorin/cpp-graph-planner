//
// Created by sacha on 25/02/24.
//

#include <vector>
#include "../include/GridGraph.h"

GridGraph::GridGraph() : width(0), height(0), eightWay(false) {

}

GridGraph::GridGraph(int width, int height, bool eightWayConn) : width(width), height(height), eightWay(eightWayConn) {
    createNodes();
    createEdges();
}

void GridGraph::createNodes() {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            this->addNode(i, j);

}

void GridGraph::createEdges() {
    for(const auto& [nodeFrom, _]: *this) {
        int x = nodeFrom.x, y = nodeFrom.y;
        vector<Coord> coords;
        coords.push_back(Coord {x + 1, y}); // North
        coords.push_back(Coord {x, y + 1}); // East
        coords.push_back(Coord {x - 1, y}); // South
        coords.push_back(Coord {x, y - 1}); // West
        if (eightWay) {
            coords.push_back(Coord {x + 1, y + 1}); // North East
            coords.push_back(Coord {x - 1, y + 1}); // South East
            coords.push_back(Coord {x - 1, y - 1}); // South West
            coords.push_back(Coord {x + 1, y - 1}); // North East
        }
        for(const auto& nodeTo: coords)
            if (this->hasNode(nodeTo))
                this->addEdge(nodeFrom, nodeTo);

    }
}
