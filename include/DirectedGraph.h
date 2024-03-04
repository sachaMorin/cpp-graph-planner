//
// Created by sacha on 16/02/24.
//

#ifndef CPP_PLANNER_DIRECTEDGRAPH_H
#define CPP_PLANNER_DIRECTEDGRAPH_H

#include <vector>
#include <map>
#include "GraphComponents.h"


class DirectedGraph {
public:
    // Build Graph
    void addNode(Coord p);

    void addNode(int x, int y);

    void addEdge(Coord p1, Coord p2);

    void addEdge(int x1, int y1, int x2, int y2, double cost);

    virtual void addEdge(Coord p1, Coord p2, double cost);

    void addEdge(int x1, int y1, int x2, int y2);

    // Read Graph
    [[nodiscard]] bool hasNode(Coord p) const;

    [[nodiscard]] bool hasNode(int x, int y) const;

    [[nodiscard]] size_t size() const; // Number of nodes

    [[nodiscard]] virtual size_t nEdges() const;

    [[nodiscard]] int nVisited() const;

    void printNodesDegrees() const;

    // A* Planning
    template<typename Callable>
    GraphPath aStar(Coord start, Coord goal, Callable heuristic);

    template<typename Callable>
    GraphPath aStar(int xStart, int yStart, int xGoal, int yGoal, Callable heuristic);

    GraphPath aStar(Coord start, Coord goal, heuristic heuristic);

    GraphPath aStar(int xStart, int yStart, int xGoal, int yGoal, heuristic heuristic);

    GraphPath aStar(Coord start, Coord goal);

    GraphPath aStar(int xStart, int yStart, int xGoal, int yGoal);

    // Iterators
    std::map<Coord, Node>::iterator begin();

    std::map<Coord, Node>::iterator end();

    [[nodiscard]] std::map<Coord, Node>::const_iterator begin() const;

    [[nodiscard]] std::map<Coord, Node>::const_iterator end() const;

protected:
    std::map<Coord, Node> nodeMap;

    GraphPath aStarPath {}; // Cache path when we call aStar

    static GraphPath reconstructPath(Node& goal) ;

private:
    void resetAStarFields();
};

#include "aStar.tpp"

#endif //CPP_PLANNER_DIRECTEDGRAPH_H
