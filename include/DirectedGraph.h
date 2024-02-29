//
// Created by sacha on 16/02/24.
//

#ifndef CPP_PLANNER_DIRECTEDGRAPH_H
#define CPP_PLANNER_DIRECTEDGRAPH_H

#include <vector>
#include <map>
#include "GraphComponents.h"

using namespace std;

class DirectedGraph {
public:
    void addNode(Coord p);

    void addNode(int x, int y);

    bool hasNode(Coord p) const;

    bool hasNode(int x, int y) const;

    virtual void addEdge(Coord p1, Coord p2, double cost);

    void addEdge(Coord p1, Coord p2);

    void addEdge(int x1, int y1, int x2, int y2, double cost);

    void addEdge(int x1, int y1, int x2, int y2);

    size_t size();

    virtual size_t nEdges() const;

    int nVisited() const;

    void printNodesDegrees() const;

    template<typename Callable>
    vector<Coord> aStar(Coord start, Coord goal, Callable heuristic);

    template<typename Callable>
    vector<Coord> aStar(int xStart, int yStart, int xGoal, int yGoal, Callable heuristic);

    vector<Coord> aStar(Coord start, Coord goal);

    vector<Coord> aStar(int xStart, int yStart, int xGoal, int yGoal);

    map<Coord, Node>::iterator begin();

    map<Coord, Node>::iterator end();

    map<Coord, Node>::const_iterator begin() const;

    map<Coord, Node>::const_iterator end() const;

protected:

    vector<Coord> aStarPath {}; // Cache path when we call aStar
    map<Coord, Node> nodeMap;

    static vector<Coord> reconstructPath(Node& goal) ;

private:
    void resetAStarFields();
};

#include "aStar.tpp"

#endif //CPP_PLANNER_DIRECTEDGRAPH_H
