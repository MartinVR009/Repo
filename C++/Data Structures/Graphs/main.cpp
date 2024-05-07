#include "graph.h" // Include the header file containing your Graph class
#include <iostream>

int main() {
  // Create a graph
  Graph<int> graph;

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
  graph.clear_();

  graph.addVertex(5);
  graph.addVertex(6);
  graph.addVertex(7);
  graph.addVertex(8);
  
  graph.addEdge(5, 6);
  graph.addEdge(7, 8);
  graph.addEdge(6, 7);
  graph.addEdge(5, 8);

  graph.printGraph();
  return 0;
}
