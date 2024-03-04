//
// Created by sacha on 15/02/24.
//

#ifndef CPP_PLANNER_GRAPHCOMPONENTS_H
#define CPP_PLANNER_GRAPHCOMPONENTS_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>


// 2D Coordinate
struct Coord {
    int x;
    int y;

    [[nodiscard]] std::string toString() const;
};

bool operator<(Coord a, Coord b);

// Graph Edge
struct Edge {
    Coord to{0, 0};
    double cost = 1.;
};

bool operator<(Edge a, Edge b);

// Graph Node
// Nodes are essentially a set of outbound edges
class Node {
public:
    Coord coord;

    explicit Node();

    explicit Node(Coord p);

    explicit Node(int x, int y);

    void addOutEdge(Edge e);

    [[nodiscard]] size_t degreeOut() const;

    // Iterators
    std::set<Edge>::iterator begin();

    std::set<Edge>::iterator end();

    [[nodiscard]] std::set<Edge>::const_iterator begin() const;

    [[nodiscard]] std::set<Edge>::const_iterator end() const;

    // A* Data Members
    Node *previous = nullptr;
    double fScore = std::numeric_limits<double>::infinity();
    double gScore = std::numeric_limits<double>::infinity();
    bool inQueue = false;

private:
    std::set<Edge> outEdges{};
};

// Graph Path returned by A*
struct GraphPath {
    std::vector<Coord> path{};
    double cost{0.};
};

// A* Heuristics
enum heuristic {
    NONE,
    TAXICAB,
    EUCLIDEAN
};


// Error Handling
struct GraphException : std::exception {
    std::string msg;

    explicit GraphException(const std::string &msg);

    const char *what() const noexcept;
};


std::string NodeErrorMsg(Coord p);

#endif //CPP_PLANNER_GRAPHCOMPONENTS_H
