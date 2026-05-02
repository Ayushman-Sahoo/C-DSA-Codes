#include <iostream>
#include <vector>
#include <list>
#include <stack>
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
        l[u].push_back(v); // directed graph for topo sort
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &s) { // dfs
        vis[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!vis[v]) {
                topoHelper(v, vis, s);
            }
        }

        s.push(src);
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topoHelper(i, vis, s);
            }
        }

        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();

    return 0;
}