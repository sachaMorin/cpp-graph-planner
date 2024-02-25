//
// Created by sacha on 25/02/24.
//

#include <vector>
#include "../include/GridGraph.h"

GridGraph::GridGraph(int width, int height) : width(width), height(height) {
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            this->addNode(i, j);

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++) {
            Coord nodeFrom {i, j};
            vector<Coord> coords;
            coords.push_back(Coord {i + 1, j}); // North
            coords.push_back(Coord {i - 1, j}); // South
            coords.push_back(Coord {i, j + 1}); // East
            coords.push_back(Coord {i, j - 1}); // West
            for(const auto& nodeTo: coords)
                if (this->hasNode(nodeTo))
                    this->addEdge(nodeFrom, nodeTo);
        }
}
