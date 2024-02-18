#include <iostream>
#include <vector>
#include "include/Graph.h"

using namespace std;

int main() {
    Graph g;

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            g.addNode(i, j);


    for (int i = 1; i < 19; i++)
        for (int j = 1; j < 19; j++) {
            g.addUndirectedEdge(i, j, i - 1, j);
            g.addUndirectedEdge(i, j, i, j - 1);
            g.addUndirectedEdge(i, j, i + 1, j);
            g.addUndirectedEdge(i, j, i, j + 1);
        }
    cout << g.size();


//    g.addNode(0, 0);
//    try {
//        g.addNode(0, 0);
//    } catch (exception& e) {
//        const char* msg = e.what();
//        cerr << msg;
//    }



    return 0;
}
