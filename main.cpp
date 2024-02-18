#include <iostream>
#include <vector>
#include "include/Graph.h"

using namespace std;

int main() {
    Graph g;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            g.addNode(i, j);


    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++) {
            g.addUndirectedEdge(i, j, i - 1, j);
            g.addUndirectedEdge(i, j, i, j - 1);
            g.addUndirectedEdge(i, j, i + 1, j);
            g.addUndirectedEdge(i, j, i, j + 1);
        }

    for (auto& [coord, node]: g) {
        cout << coord.to_string() << ": " << node.degreeOut() << endl;
    }




//    g.addNode(0, 0);
//    try {
//        g.addNode(0, 0);
//    } catch (exception& e) {
//        const char* msg = e.what();
//        cerr << msg;
//    }



    return 0;
}
