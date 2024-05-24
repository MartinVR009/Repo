#include "graph.h"
#include <utility>
#include <limits>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::pair<T,T>& p){
    return s << "{" << p.first << ", " << p.second<< "} ";
}

template<typename T>
bool operator==(const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}


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

template<typename T>
void Graph<T>::prim(){
    
}

bool notIn(std::vector<std::pair<int,int>> vect, std::pair<int,int> data){
    for(std::pair<int,int> p : vect){
        if(p == data){
            return false;
        }
    }
    return true;
}

template <typename T>
std::pair<int, int> Graph<T>::minEdge(std::vector<bool> inMST, std::vector<std::pair<int,int>> visited) {
        double minWeight = std::numeric_limits<double>::max();
        std::pair<int, int> minEdgeIndices;
        
        for (int i = 0; i < total_elements; i++) {
            std::cout <<"inMST[" << i <<"] es " << inMST[i] <<  "\n";
            if(inMST[i]){
                for (int col = 0; col < total_elements; ++col) {
                    if (graph[col][i] != 0 && graph[col][i] < minWeight && notIn(visited, {i,col}) && !inMST[col]) {
                        std::cout << "Vertex["<<i<<"] = << "<<vertex[i] <<  "vs Vertex[" <<col <<"]="<<vertex[col] << "Distancia: " << graph[col][i] << "\n";
                        minWeight = graph[col][i];
                        minEdgeIndices = {i, col};
                    }
                }
            }
        }
        std::cout<<"Termino uno!\n";
        std::cout<<"minWeight = " << minWeight << "\n";
        std::cout<<"minEdgeIndices = " << minEdgeIndices <<"\n";

        return minEdgeIndices;
    }
template<typename T>
void Graph<T>::primXY(std::vector<std::pair<T, T>> &mst){

        // Vector para marcar los vértices incluidos en el MST
        std::vector<bool> inMST(total_elements, false);

        std::vector<std::pair<int,int>> visited_edges(total_elements);

        std::pair<int,int>temp;
        // Elegir un vértice aleatorio como punto de inicio
        int startVertex = 0;

        //mst.push_back({vertex[startVertex], vertex[startVertex]});
        inMST[startVertex] = true;
        
        while (mst.size() != total_elements-1)
        {   
            // Encontrar el vértice más cercano no incluido en el MST
            temp = minEdge(inMST, visited_edges);
            visited_edges.push_back(temp);
            inMST[temp.second] = true;
            mst.push_back({vertex[temp.first],vertex[temp.second]});
        }

        std::cout << "Arbol de Minima Expansion:" << std::endl;
        for (const auto& edge : mst) {
            std::cout << edge.first << " - " << edge.second << std::endl;
        }
}

template<typename T>
struct Dijkstra_data<T> Graph<T>::Dijkstra(T origin){

    std::vector<T> S; //visited
    std::vector<float> dist(total_elements, INF);
    std::vector<T> pred(total_elements);
    float min;

    int index_a = returnIndex(origin);
    S.push_back(origin);
    pred[index_a] = vertex[index_a];
    dist[index_a] = 0;
    while(S.size() < total_elements){
        for(int i = 0; i < total_elements; i++){
            if(graph[index_a][i] != 0){
                if(dist[i] > graph[index_a][i] + dist[index_a]){
                    dist[i] = graph[index_a][i] + dist[index_a];
                    pred[i] = vertex[index_a];
                }
            }
        }
        min = INF;
        for(int i = 0; i < total_elements; i++){
            if(dist[i] < min && !data_in(S,vertex[i])){
                index_a = returnIndex(vertex[i]);
            }
        }
        S.push_back(vertex[index_a]);
    }
    struct Dijkstra_data<T> data_r;
    data_r.distance = dist;
    data_r.predecesors = pred;

    return data_r;

}

template<typename T>
void Graph<T>::shortest_path(T origin, T destiny) {
    // Obtener los resultados del algoritmo de Dijkstra
    Dijkstra_data<T> dijkstra;
    dijkstra = Dijkstra(origin);

    // Reconstruir el camino más corto desde el vértice de destino hasta el origen
    std::stack<T> path;
    T current_vertex = destiny;
    while (current_vertex != origin) {
        path.push(current_vertex);
        // Obtener el predecesor del vértice actual en el camino más corto
        T predecessor = dijkstra.predecesors[returnIndex(vertex, current_vertex)];
        current_vertex = predecessor;
    }
    // Agregar el vértice de origen al camino
    path.push(origin);
    
    // Imprimir el camino más corto
    while (!path.empty()) {
        T data = path.top();
        std::cout << data;
        path.pop();
        if(!path.empty()){
            std::cout<<"->";
        }
    }
    std::cout << std::endl;
}

template<typename T>
void Graph<T>::DFScomponent(T v, std::vector<bool>& visited) {
    visited[returnIndex(v)] = true;
    std::cout << v << " ";

    for (int i = 0; i < total_elements; ++i) {
        if (graph[returnIndex(v)][i] && !visited[i]) {
            DFScomponent(vertex[i], visited);
        }
    }
}

template<typename T>
void Graph<T>::componentes() {
    std::vector<bool> visited(total_elements, false);

    for (int v = 0; v < total_elements; ++v) {
        if (!visited[v]) {
            DFScomponent(vertex[v], visited);
            std::cout << std::endl;
        }
    }
}

//Todos los posibles caminos con DFS


using namespace std;

//Algoritmos Parcial
template <typename K>
void path_a(vector<vector<K>>& graph, vector<vector<K>>& result, vector<K>& path, K actual, K target) {
        path.push_back(actual);
        if (actual == target) {
            result.push_back(path);
        } else {
            for (int i = 0; i < total_elements; i++) {
                if(graph[actual][i] != 0){
                    path_a(graph, result, path, vertex[i], target);
                }
            }
        }
        path.pop_back(); 
}


Graph<int> graph;

template <typename K>
vector<vector<K>> allPaths(K origin, K target){
    vector<vector<K>> result;
    vector<K> path;
    path_a(graph, result, path, origin, target);
}