#include "graph.h"

template<typename T>
Vertex<T>::Vertex(int index, T data){
    this->index = index;
    this->data = data;
    this->fnd = false;
}

template<typename T>
Vertex<T>::Vertex(T data){
    this->index = 0;
    this->data = data;
    this->fnd = false;
}


//Graph
template<typename T, typename A>
Graph<T,A>::Graph(){
    undirected = true;
    total_elements = 0;
}

template<typename T, typename A>
Graph<T,A>::Graph(bool directed, bool weighted){
    this->undirected = directed;
    this->weighted =  weighted;
}

template<typename T, typename A>
Graph<T,A>::Graph(T data, bool directed, bool weighted){
    vertex.push_back(Vertex<T>(0, data));
    total_elements = 1;
    this->undirected = directed;
    this->weighted =  weighted;
}

template<typename T, typename A>
Graph<T,A>::Graph( T data, int weight, bool directed, bool weighted){
    vertex.push_back(Vertex<T>(0, data, weight));
    total_elements = 1;
    this->undirected = directed;
    this->weighted =  weighted;
}

//Gets 
template<typename T, typename A>
int Graph<T,A>::getTotalElements(){
    return total_elements;
}

template<typename T, typename A>
std::vector<std::vector<Edge<A>>> Graph<T,A>::getGraph(){
    return graph;
}

template<typename T, typename A>
std::vector<Vertex<T>> Graph<T,A>:: getVertex(){
    return vertex;
}

//Methods
template<typename T, typename A>
void Graph<T,A>::addVertex(T data){
    Vertex<T> vertex_add(total_elements++, data);
    vertex.push_back(vertex_add);
}


template<typename T, typename A>
void Graph<T,A>::addVertexV(Vertex<T> vertex_add){
    vertex_add.index = total_elements++;
    vertex_add.fnd = false;
    vertex.push_back(vertex_add);
}

template<typename T, typename A>
int Graph<T,A>::returnIndex(T data){
    for(Vertex<T> v : vertex){
        if(v.data == data){
            return v.index;
        }
    }
}

template<typename T, typename A>
void Graph<T,A>::addEdge(T origin, T destiny){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);

    // If the graph is empty, fill it with the adjacency matrix
    if(graph.empty()){
        fillGraph();
    }
    graph[origin_idx][destiny_idx] = Edge<A>(1);
    if(undirected){
        graph[destiny_idx][origin_idx] = Edge<A>(1);
    }
}

template<typename T, typename A>
void Graph<T,A>::deleteEdge(T origin, T destiny){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);

    graph[origin_idx][destiny_idx] = Edge<A>(0);
    if(undirected){
        graph[destiny_idx][origin_idx] = Edge<A>(0);
    }
}

template<typename T, typename A>
void Graph<T,A>::addEdgeW(T origin, T destiny, A weight){
    int origin_idx = returnIndex(origin);
    int destiny_idx = returnIndex(destiny);

    // If the graph is empty, fill it with the adjacency matrix
    if(graph.empty()){
        fillGraph();
    }
    graph[origin_idx][destiny_idx] = Edge<A>(1);
    if(undirected){
        graph[destiny_idx][origin_idx] = Edge<A>(1);
    }
}

template<typename T, typename A>
void Graph<T,A>::fillGraph(){
    for(int i = 0; i < total_elements; i++){
        std::vector<Edge<A>> temp;
        for(int j = 0; j < total_elements; j++){
            temp.push_back(Edge<A>());    
        }
        graph.push_back(temp);
    }
}

template<typename T, typename A>
void Graph<T, A>::printGraph() {
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
            std::cout << graph[i][j].weight << " "; // Print the connection weight
        }
        std::cout << std::endl;
    }
}



