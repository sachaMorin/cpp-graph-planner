#include <iostream>
#include <vector>
#include <map>
#include "include/Node.h"

using namespace std;

int main() {
    vector<Node *> v;
    map<Coord, Node> nodeMap;

    for(auto i = 0; i < 100; i++) {
        Coord p {i, 0};
        Node n = Node(p);
        nodeMap[p] = n;
        v.push_back(&n);
    }

    long s = nodeMap.size();
    cout << s;

    for (auto x: v) {

    }


    return 0;
}
