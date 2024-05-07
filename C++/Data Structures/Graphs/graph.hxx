#include "graph.h"

//Graph
template<typename T>
Graph<T>::Graph(){
    undirected = true;
    total_elements = 0;
}

template<typename T>
Graph<T>::Graph(bool directed){
    this->undirected = directed;
    total_elements = 0;
}

//Gets 
template<typename T>
int Graph<T>::getTotalElements(){
    return total_elements;
}

template<typename T>
std::vector<std::vector<double>> Graph<T>::getGraph(){
    return graph;
}

template<typename T>
std::vector<T> Graph<T>:: getVertex(){
    return vertex;
}

//Methods
template<typename T>
void Graph<T>::addVertex(T data){
    total_elements++;
    vertex.push_back(data);
    std::vector<double> temp;
}

template<typename T>
int Graph<T>::returnIndex(T data){
    int i = 0;
    for(T v : vertex){
        if(v == data){
            return i;
        }
        i++;
    }
  return -1;
}

template<typename T>
void Graph<T>::addEdge(T origin, T destiny){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);
    
    // If the graph is empty, fill it with the adjacency matrix
    if(graph.empty()){
        fillGraph();
    }
    graph[origin_idx][destiny_idx] = 1;
    if(undirected){
        graph[destiny_idx][origin_idx] = 1 ;
    }
}

template<typename T>
void Graph<T>::deleteEdge(T origin, T destiny){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);

    graph[origin_idx][destiny_idx] = 0;
    if(undirected){
        graph[destiny_idx][origin_idx] = 0;
    }
}

template<typename T>
void Graph<T>::addEdgeW(T origin, T destiny, double weight){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);

    // If the graph is empty, fill it with the adjacency matrix
    if(graph.empty()){
        fillGraph();
    }

    graph[origin_idx][destiny_idx] = weight;
    if(undirected){
        graph[destiny_idx][origin_idx] = weight;
    }
}

template<typename T>
void Graph<T>::fillGraph(){
    for(int i = 0; i < total_elements; i++){
        std::vector<double> temp;
        for(int j = 0; j < total_elements; j++){
            temp.push_back(0);    
        }
        graph.push_back(temp);
    }
}

template<typename T>
void Graph<T>::printGraph() {
    // Print the header row with vertex indices
    std::cout << "  ";
    for (int i = 0; i < total_elements; ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    // Print the matrix
    for (int i = 0; i < total_elements; ++i) {
        std::cout << i + 1 << " "; // Print the vertex index

        for (int j = 0; j < total_elements; ++j) {
            std::cout << graph[i][j] << " "; // Print the connection weight
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Graph<T>:: DFS(T origin, int mode){
    std::vector<T> visited;
    if(mode == 1){
        DFS_recursion(origin, visited);
    }else{
        DFS_stack(origin,visited);
    }
}

template<typename T>
void Graph<T>::DFS_recursion(T origin, std::vector<T> &visited){
  int temp = returnIndex(origin);
  visited.push_back(origin);
  std::cout<<vertex[temp]<<",";
  for(int i = 0; i < total_elements; i++){
    if(graph[i][temp] >= 1){
      if(!data_in(visited,vertex[i])){
        DFS_recursion(vertex[i],visited);
      }
    }
  }
}

template<typename T>
void Graph<T>::DFS_stack(T origin, std::vector<T> &visited){
  std::stack<T> visited_stack;
  visited_stack.push(origin);

  while(!visited_stack.empty()){
    T actual = visited_stack.top();
    visited_stack.pop();
    if(!data_in(visited, vertex[returnIndex(actual)])){
      std::cout<<actual<<",";
      visited.push_back(vertex[returnIndex(actual)]);
      for(int i = 0; i < total_elements; i++){
        if(graph[i][returnIndex(actual)] >= 1 && !data_in(visited, vertex[i])){
          visited_stack.push(vertex[i]);
        }
      }
    }
  }
}

/*std::cout <<"\n Index: " << i << " Value: " << vertex[i].getData() << " Weight: " << graph[i][returnIndex(actual)].weight <<" \n";
        if(graph[i][returnIndex(actual)].weight >= 1 && !vertex[i].getFND()){
          std::cout <<"\n"<<vertex[i].getData() <<" Added to stack!\n";*/

template<typename T>
void Graph<T>::level(T origin){
  std::vector<T> visited;
  std::queue<T> visited_queue;
  visited_queue.push(origin);

  while(!visited_queue.empty()){
    T actual = visited_queue.front();
    visited_queue.pop();
    if(!data_in(visited, vertex[returnIndex(actual)])){
      std::cout << actual <<",";
      visited.push_back(vertex[returnIndex(actual)]);
      for(int i = 0; i < total_elements; i++){
        if(graph[i][returnIndex(actual)] >= 1 && !data_in(visited,vertex[i])){
          visited_queue.push(vertex[i]);
        }
      }
    }
  }
}

template<typename T>
bool Graph<T>::data_in(std::vector<T> vect, T data){
    for(T v : vect){
        if(v == data){
            return true;
        }
    }
    return false;
}

template<typename T>
void Graph<T>::clear_(){
    vertex.clear();
    for(auto &row : graph){
        row.clear();
    }
    graph.clear();
    total_elements = 0;
}


