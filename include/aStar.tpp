//
// Created by sacha on 26/02/24.
//

// Provide a header implementation of template members in a separate file
// See https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

#include <queue>
#include "DirectedGraph.h"

template<typename Callable>
GraphPath DirectedGraph::aStar(Coord start, Coord goal, Callable heuristic) {
    // A* Implementation based on Wikipedia
    // Nodes store their own previous pointer, fScore, gScore and inQueue values
    // and are accessible in nodeMap
    if (!hasNode(start))
        throw GraphException("Start node " + start.to_string() + " is not in the graph.");
    if (!hasNode(goal))
        throw GraphException("Goal node " + goal.to_string() + " is not in the graph.");

    resetAStarFields();

    Node& startNode = nodeMap[start];
    Node& goalNode = nodeMap[goal];

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known
    startNode.gScore = 0.0;

    // For node n, fScore[n] := gScore[n] + h(n). fScore[n] represents our best guess as to
    // how cheap a path could be from start to finish if it goes through n.
    startNode.fScore = heuristic(startNode.coord, goalNode.coord);

    // Set up min priority queue comparing Node fScores
    auto cmp = [] (const Node* left, const Node* right) {return left->fScore > right->fScore;};
    priority_queue<Node*, vector<Node*>, decltype(cmp)> openSet;

    openSet.push(&startNode);
    startNode.inQueue = true;


    while(!openSet.empty()) {
        Node* minNode = openSet.top();
        if (minNode == &goalNode) {
            aStarPath = reconstructPath(goalNode);
            auto result = aStarPath;
            return result; // Return copy
        }

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
GraphPath DirectedGraph::aStar(int xStart, int yStart, int xGoal, int yGoal, Callable heuristic) {
    return aStar(Coord {xStart, yStart}, Coord {xGoal, yGoal}, heuristic);
}
