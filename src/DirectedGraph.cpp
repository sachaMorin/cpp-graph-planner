//
// Created by sacha on 16/02/24.
//

#include "string"
#include "cmath"
#include <queue>
#include "../include/DirectedGraph.h"

using namespace std;

void DirectedGraph::addNode(Coord p) {
    if (hasNode(p))
        throw GraphException("Node with coordinates " + p.to_string() + " already exists");

    nodeMap[p] = Node(p);
}

void DirectedGraph::addNode(int x, int y) {
    addNode(Coord{x, y});
}

bool DirectedGraph::hasNode(Coord p) const {
    return nodeMap.count(p) > 0;
}

bool DirectedGraph::hasNode(int x, int y) const {
    return hasNode(Coord{x, y});
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

size_t DirectedGraph::size() {
    return nodeMap.size();
}

size_t DirectedGraph::nEdges() const {
    size_t result = 0;
    for (auto &[coord, node]: *this)
        result += node.degreeOut();
    return result;
}

void DirectedGraph::printNodesDegrees() const {
    for (auto const &[coord, node]: *this)
        cout << coord.to_string() << ": " << node.degreeOut() << "\n";
}

template<typename Callable>
vector<Coord> DirectedGraph::aStar(Coord start, Coord goal, Callable heuristic) {
    // Set up min priority queue comparing Node fscores
    auto cmp = [] (const Node* left, const Node* right) {return left->fScore > right->fScore;};
    priority_queue<Node*, vector<Node*>, decltype(cmp)> openSet;

    // Draft
    for(auto& [coord, current]: *this) {
        current.fScore = heuristic(coord, goal);
        openSet.push(&current);
    }

    // Check order in queue
    while (!openSet.empty()) {
        Node* topNode = openSet.top();
        cout << topNode->coord.to_string() << " : " << topNode->fScore << "\n";
        openSet.pop();
    }

    vector<Coord> path;
    path.push_back(start);
    path.push_back(goal);
    return path;
}

template<typename Callable>
vector<Coord> DirectedGraph::aStar(int xStart, int yStart, int xGoal, int yGoal, Callable heuristic) {
    return aStar(Coord {xStart, yStart}, Coord {xGoal, yGoal}, heuristic);
}

vector<Coord> DirectedGraph::aStar(Coord start, Coord goal) {
    auto euclideanDist = [] (Coord c1, Coord c2) {
        return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
    };
    return aStar(start, goal, euclideanDist);
}

vector<Coord> DirectedGraph::aStar(int xStart, int yStart, int xGoal, int yGoal) {
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


