//
// Created by sacha on 16/02/24.
//

#include <string>
#include <cmath>
#include <list>
#include <functional>
#include "DirectedGraph.h"

using namespace std;

void DirectedGraph::addNode(Coord p) {
    if (hasNode(p))
        throw GraphException("Node with coordinates " + p.toString() + " already exists");

    nodeMap[p] = Node(p);
}

void DirectedGraph::addNode(int x, int y) {
    addNode(Coord{x, y});
}

void DirectedGraph::addEdge(Coord p1, Coord p2, double cost) {
    if (!hasNode(p1))
        throw GraphException(NodeErrorMsg(p1));
    if (!hasNode(p2))
        throw GraphException(NodeErrorMsg(p2));
    nodeMap[p1].addOutEdge(Edge{p2, cost});
}

void DirectedGraph::addEdge(Coord p1, Coord p2) {
    addEdge(p1, p2, 1.);
}

void DirectedGraph::addEdge(int x1, int y1, int x2, int y2, double cost) {
    addEdge(Coord{x1, y1}, Coord{x2, y2}, cost);
}

void DirectedGraph::addEdge(int x1, int y1, int x2, int y2) {
    addEdge(Coord{x1, y1}, Coord{x2, y2}, 1.);
}

bool DirectedGraph::hasNode(Coord p) const {
    return nodeMap.count(p) > 0;
}

bool DirectedGraph::hasNode(int x, int y) const {
    return hasNode(Coord{x, y});
}

size_t DirectedGraph::size() const {
    return nodeMap.size();
}

int DirectedGraph::nVisited() const {
    // Check nodes visited by A*
    int result = 0;
    for (auto const &[_, node]: *this)
        if (node.gScore < numeric_limits<double>::infinity())
            result += 1;
    return result;
}

size_t DirectedGraph::nEdges() const {
    size_t result = 0;
    for (auto &[coord, node]: *this)
        result += node.degreeOut();
    return result;
}

void DirectedGraph::printNodesDegrees() const {
    for (auto const &[coord, node]: *this)
        cout << coord.toString() << ": " << node.degreeOut() << "\n";
}

GraphPath DirectedGraph::aStar(Coord start, Coord goal, heuristic heuristic) {
    std::function<double(Coord, Coord)> h;
    switch(heuristic) {
        case NONE: {
            h = [] (Coord c1, Coord c2) {
                return 0.0;
            };
            break;
        }
        case TAXICAB: {
            h = [] (Coord c1, Coord c2) {
                return abs(c1.x - c2.x) + abs(c1.y - c2.y);
            };
            break;
        }
        case EUCLIDEAN: {
            h = [] (Coord c1, Coord c2) {
                return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
            };
            break;
        }

        default:
            throw GraphException("Invalid heuristic code.");
    }
    return aStar(start, goal, h);
}

GraphPath DirectedGraph::aStar(int xStart, int yStart, int xGoal, int yGoal, heuristic heuristic) {
    return aStar(Coord {xStart, yStart}, Coord {xGoal, yGoal}, heuristic);
}

GraphPath DirectedGraph::aStar(Coord start, Coord goal) {
    return aStar(start, goal, EUCLIDEAN);
}

GraphPath DirectedGraph::aStar(int xStart, int yStart, int xGoal, int yGoal) {
    return aStar(Coord {xStart, yStart}, Coord {xGoal, yGoal});
}

map<Coord, Node>::iterator DirectedGraph::begin() {
    return nodeMap.begin();
}

map<Coord, Node>::iterator DirectedGraph::end() {
    return nodeMap.end();
}

map<Coord, Node>::const_iterator DirectedGraph::begin() const {
    return nodeMap.cbegin();
}

map<Coord, Node>::const_iterator DirectedGraph::end() const {
    return nodeMap.cend();
}

void DirectedGraph::resetAStarFields()  {
    for(auto& [_, node]: *this) {
        node.previous = nullptr;
        node.fScore = numeric_limits<double>::infinity();
        node.gScore = numeric_limits<double>::infinity();
        node.inQueue = false;
    }
    aStarPath = {};
}

GraphPath DirectedGraph::reconstructPath(Node& goal) {
    // Reconstruct path
    list<Coord> path;
    Node* currentNode = &goal;

    // Start will have a previous nullptr
    while (currentNode != nullptr) {
        path.push_back(currentNode->coord);
        currentNode = currentNode->previous;
    }
    path.reverse();

    GraphPath result {{path.begin(), path.end()}, goal.gScore};

    return result;
}


