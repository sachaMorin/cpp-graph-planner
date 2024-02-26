//
// Created by sacha on 16/02/24.
//

#include "string"
#include "cmath"
#include <queue>
#include <list>
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
    // A* Implementation based on Wikipedia
    // Nodes store their own previous pointer, fScore, gScore and inQueue values
    // and are accessible in nodeMap
    resetAStarFields();

    Node& startNode = nodeMap[start];
    Node& goalNode = nodeMap[goal];

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known
    startNode.gScore = 0.0;

    // For node n, fScore[n] := gScore[n] + h(n). fScore[n] represents our startNode best guess as to
    // how cheap a path could be from start to finish if it goes through n.
    startNode.fScore = heuristic(startNode.coord, goalNode.coord);

    // Set up min priority queue comparing Node fScores
    auto cmp = [] (const Node* left, const Node* right) {return left->fScore > right->fScore;};
    priority_queue<Node*, vector<Node*>, decltype(cmp)> openSet;

    openSet.push(&startNode);
    startNode.inQueue = true;


    while(!openSet.empty()) {
        Node* minNode = openSet.top();
        if (minNode == &goalNode)
            return reconstructPath(goalNode);

        openSet.pop();
        minNode->inQueue = false;

        for (const Edge outEdge : *minNode) {
            Node& neighbor = nodeMap[outEdge.to];
            double tentativeGScore = minNode->gScore + outEdge.cost;
            if (tentativeGScore < neighbor.gScore) {
                neighbor.previous = minNode;
                neighbor.gScore = tentativeGScore;
                neighbor.fScore = tentativeGScore + heuristic(neighbor.coord, goalNode.coord);
                if (!neighbor.inQueue) {
                    openSet.push(&neighbor);
                    neighbor.inQueue = true;
                }
            }
        }
    }

    // Return empty path if no path exists
    return {};
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

void DirectedGraph::resetAStarFields()  {
    for(auto& [_, node]: *this) {
        node.previous = nullptr;
        node.fScore = numeric_limits<double>::infinity();
        node.gScore = numeric_limits<double>::infinity();
        node.inQueue = false;
    }
}

vector<Coord> DirectedGraph::reconstructPath(Node& goal) {
    // Reconstruct path
    list<Coord> path;
    Node* currentNode = &goal;

    // Only start has gScore 0
    while (currentNode->gScore != 0) {
        path.push_back(currentNode->coord);
        currentNode = currentNode->previous;
        if (currentNode == nullptr)
            throw GraphException("Bumped into a nullptr while reconstructing path. This should not happen");
    }
    path.reverse();

    return {path.begin(), path.end()};
}


