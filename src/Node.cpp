//
// Created by sacha on 15/02/24.
//

#include "../include/Node.h"

Node::Node() {

}

Node::Node(Coord p) : nodeCoord(p) {
}

Node::Node(int x, int y) : nodeCoord(Coord {x, y}) {

}

bool operator<(Coord a, Coord b) {
    if (a.x < b.x)
        return true;
    return a.y < b.y;
}
