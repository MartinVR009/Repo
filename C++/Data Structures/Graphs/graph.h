#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <string>

template <typename T>
struct Edge
{
    T weight;
    bool visited;

    Edge(){
        this->weight = 0;
        visited = false;
    }

    Edge(T weight){
        this->weight = weight;
        visited = false;
    }
};


template <typename T>
class Vertex{
    public:
        T data;
        int index;
        bool fnd;

        Vertex(T data);
        Vertex(int index, T data);

        T getData();
        int getIndex();
        bool getFND();

        operator==(const Vertex& b) const{
            return this->data == b.data;
        }
};  

template <typename T, typename A> //If unweighted graph, A go int for easier use
class Graph{
    private:
        bool undirected;
        bool weighted;
        int total_elements;
        std::vector<Vertex<T>> vertex;
        std::vector<std::vector<Edge<A>>> graph;

    public:
        //Constructors
        Graph();
        Graph(bool directed, bool weighted);
        Graph(T data, bool directed, bool weighted);
        Graph(T data, int weight, bool directed, bool weighted);

        //Gets
        int getTotalElements();
        std::vector<std::vector<Edge<A>>> getGraph();
        std::vector<Vertex<T>> getVertex();

        //Methods
        void addVertexV(Vertex<T> vertex_add);
        void addVertex(T data);
        int returnIndex(T data);

        //Only available when Graph is weighted = true;
        void addVertexWeight(T data, A weight);
        void addEdgeW(T origin, T destiny, A weight);

        //Edge Management
        void addEdge(T origin, T destiny);
        void deleteEdge(T origin, T destiny);
        
        void fillGraph();
        void printGraph();
};

#include "graph.hxx"

#endif