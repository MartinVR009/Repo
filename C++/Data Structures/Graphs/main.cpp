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
  graph.DFS(3, 1); // Calls recursive

  std::cout << "\n Stack\n";

  graph.DFS(3, 0); // Calls Stack

  std::cout << "\n Level \n";

  graph.level(1);

  std::cout << "\nFin\n";
  return 0;
}
