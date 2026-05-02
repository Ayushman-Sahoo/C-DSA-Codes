// C++ program to print all the disconnected components of a graph
// DFS is used to print the components of the graph
/*
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(10);

    // Component 1
    g.addEdge(1, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 7);

    // Component 2
    g.addEdge(2, 5);
    g.addEdge(2, 0);

    g.dfs();

    return 0;
}  */

// BFS is used to print the components of the graph
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Helper function
    void bfsHelper(int start, vector<bool> &vis) {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            list<int> neighbors = l[curr];

            for(int neigh : neighbors) {
                if(!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }

    // BFS for disconnected components
    void bfs() {
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bfsHelper(i, vis);
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(10);

    // Component 1
    g.addEdge(1, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 7);

    // Component 2
    g.addEdge(2, 5);
    g.addEdge(2, 0);

    g.bfs();

    return 0;
}