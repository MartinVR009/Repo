#include <iostream>
#include "graph.h" // Include the header file containing your Graph class

int main() {
    // Create a graph
    Graph<int, int> graph;

    // Add some vertices
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();
    return 0;
}
