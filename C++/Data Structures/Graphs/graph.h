#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

template <typename T> // If unweighted graph, A go int for easier use
class Graph {
private:
  bool undirected;
  int total_elements;
  std::vector<T> vertex;
  std::vector<std::vector<double>> graph;

public:
  // Constructors
  Graph();
  Graph(bool directed);

  // Gets
  int getTotalElements();
  std::vector<std::vector<double>> getGraph();
  std::vector<T> getVertex();

  // Methods
  void addVertexV(T vertex_add);
  void addVertex(T data);
  int returnIndex(T data);

  // Only available when Graph is weighted = true;
  void addVertexWeight(T data, double weight);
  void addEdgeW(T origin, T destiny, double weight);

  // Edge Management
  void addEdge(T origin, T destiny);
  void deleteEdge(T origin, T destiny);

  void fillGraph();
  void printGraph();

  // Traverse
  void flat();
  void DFS(T origin, int mode);
  void DFS_stack(T origin, std::vector<T> &visited);
  void DFS_recursion(T origin, std::vector<T> &visited);
  void level(T origin);

  // Algorithms
  void STP(T origin, T destiny);

  // Others
  void clear_();
  bool data_in(std::vector<T> visited, T data);
};

#include "graph.hxx"

#endif