#include <iostream>
#include <vector>
#include <map>
#include "include/Graph.h"

using namespace std;

int main() {
    Graph g;

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            g.addNode(i, j);

    cout << g.size();


    return 0;
}
