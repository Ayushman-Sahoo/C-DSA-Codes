#include <iostream>
#include <vector>
#include <list>
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

    void pathHelper(int src, int dst, vector<bool> &vis, string &path) {
        path += to_string(src);   // FIXED

        if (src == dst) {
            cout << path << endl;
            path.pop_back();      // FIXED (minimal change)
            return;
        }

        path += "->";             // FIXED
        vis[src] = true;

        list<int> neighbours = l[src];

        for (int v : neighbours) {
            if (!vis[v]) {
                pathHelper(v, dst, vis, path);
            }
        }

        path.pop_back();          // FIXED
        path.pop_back();          // FIXED (remove "->")
        vis[src] = false;
    }

    void printAllPath(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "All paths from 0 to 4:\n";
    g.printAllPath(0, 4);

    return 0;
}