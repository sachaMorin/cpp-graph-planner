//
// Created by sacha on 15/02/24.
//

#ifndef CPP_PLANNER_NODE_H
#define CPP_PLANNER_NODE_H

#include <vector>

using namespace std;

struct Coord {
    int x;
    int y;
};

bool operator<(Coord a, Coord b);

class Node {
    Coord nodeCoord;
    std::vector<Coord> neighbors {};
public:
    explicit Node();
    explicit Node(Coord p);
    explicit Node(int x, int y);
};


#endif //CPP_PLANNER_NODE_H
