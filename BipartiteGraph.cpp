#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndirected;

public:
    Graph(int V, bool isUndirected = true) {
        this->V = V;
        l = new list<int>[V];
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndirected) {
            l[v].push_back(u);
        }
    }

    // DFS helper (fixed)
    bool isBipartiteHelper(int src, vector<int> &color) {
        for(int v : l[src]) {
            if(color[v] == -1) {
                color[v] = 1 - color[src];
                if(!isBipartiteHelper(v, color)) {
                    return false;
                }
            } 
            else if(color[v] == color[src]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite() {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;
        vis[0] = true;

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();

            list<int> neighbors = l[curr];

            for(int v : neighbors) {
                if(!vis[v]) {
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }
                else if(color[v] == color[curr]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if(g.isBipartite()) {
        cout << "Graph is Bipartite\n";
    } else {
        cout << "Graph is NOT Bipartite\n";
    }

    return 0;
}