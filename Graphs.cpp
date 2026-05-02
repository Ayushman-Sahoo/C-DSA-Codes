#include <iostream>
#include <list>
using namespace std;

//This is the implementation of an undirected graph using an adjacency list. The Graph class has a constructor that initializes the number of vertices and creates an array of lists to represent the adjacency list. The addEdge function adds an edge between two vertices, and the printGraph function prints the adjacency list representation of the graph. The main function demonstrates how to create a graph, add edges, and print the graph. This code is for unweighted graphs, but it can be easily modified to support weighted graphs by using a pair of integers (vertex and weight) instead of just an integer in the adjacency list.
/*
class Graph{
  int V;
  list<int> *adjList;
public:
  Graph(int V){
    this->V = V;
    adjList = new list<int>[V];
  }

  void addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void printGraph(){
    for(int i = 0; i < V; i++){
      list<int> neighbors = adjList[i];
      cout << "Vertex " << i << ": ";
      for(int v : adjList[i]){
        cout << v << " ";
      }
      cout << endl;
    }
  }
};

int main(){
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);

  graph.printGraph();
  return 0;
}*/


// 

class Graph {
    int V;
    list<pair<int, int>> *adjList; // (neighbor, weight)
public:
    Graph(int V) {
        this->V = V;
        adjList = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (auto neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", weight: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 2);

    graph.printGraph();
    return 0;
}