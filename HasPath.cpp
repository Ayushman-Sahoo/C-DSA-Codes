/*Given a graph, check if there is at least one path from node src to node dest.

Return true (T) if a path exists
Return false (F) if no path exists*/

//DFS
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasPathDFS(int src, int dest, vector<bool>& visited) {
        if (src == dest) return true;   // base case

        visited[src] = true;
        
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (hasPathDFS(neighbor, dest, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    int src = 0, dest = 5;

    vector<bool> visited(7, false);

    if (g.hasPathDFS(src, dest, visited))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}

// BFS
/*#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasPathBFS(int src, int dest) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) return true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    int src = 0, dest = 5;

    if (g.hasPathBFS(src, dest))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}*/