#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int start, vector<bool> &visited) {
        visited[start] = true;              // fixed
        cout << start << " ";               // fixed

        list<int> neighbors = adjList[start];   // fixed
        for (int v : neighbors) {
            if (!visited[v]) {
                dfs(v, visited);           // fixed
            }
        }
    }

    int getV() { return V; } // added to access V safely
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    vector<bool> visited(7, false);  // fixed
    graph.dfs(0, visited);

    return 0;
}