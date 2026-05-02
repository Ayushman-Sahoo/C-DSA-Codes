// C++ program to detect cycle in an undirected graph using DFS
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

   void addEdge(int u, int v) { // u --- v
    l[u].push_back(v);
    l[v].push_back(u);
}

    void print() {
    for(int u = 0; u < V; u++) {  // 0,1,2,3,4...
        list<int> neighbors = l[u];
        cout << u << " : ";

        for(int v : neighbors) {
            cout << v << " ";
        }

        cout << endl;
    }
}

bool undirCycleHelper(int src, int par, vector<bool> &vis) {
    vis[src] = true;
    list<int> neighbors = l[src];

    for(int v : neighbors) {
        if(!vis[v]) {
            if(undirCycleHelper(v, src, vis)) {
                return true;
            }
        } else {
            if(v != par) {  // cycle condition
                return true;
            }
        }
    }

    return false;
}

    bool isCycleUndirected() {
    vector<bool> vis(V, false);

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(undirCycleHelper(i, -1, vis)) {
                return true;
            }
        }
    }

    return false;
    }
};

int main() {
    Graph g(5);

    // undirected graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1, 2);

    g.addEdge(3, 4);

    g.print();
    cout << g.isCycleUndirected() << endl;

    return 0;
}*/

// C++ program for directed graph cycle detection using DFS
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

   void addEdge(int u, int v) { // u --- v
    l[u].push_back(v);
    if (isUndirected)
    {
        l[v].push_back(u);
    }
}

    void print() {
    for(int u = 0; u < V; u++) {  // 0,1,2,3,4...
        list<int> neighbors = l[u];
        cout << u << " : ";

        for(int v : neighbors) {
            cout << v << " ";
        }

        cout << endl;
    }
}

bool dirCycleDirectedHelper(int src, vector<bool> &vis, vector<bool> &recStack) {
    vis[src] = true;
    recStack[src] = true;

    list<int> neighbors = l[src];

    for(int v : neighbors) {
        if(!vis[v]) {
            if(dirCycleDirectedHelper(v, vis, recStack)) {
                return true;
            }
        } else {
            if(recStack[v]) {  // cycle condition
                return true;
            }
        }
    }

    recStack[src] = false; // backtracking
    return false;
}

bool isCycleDirected(){
  vector<bool> vis(V, false);
  vector<bool> recStack(V, false);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (dirCycleDirectedHelper(i, vis, recStack)) // ✅ fixed name
      {
        return true;
      }
    }
  }
  return false;
}
};

int main() {
    Graph g(5, false);

    // directed graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1, 2);

    g.addEdge(3, 4);

    g.print();

    return 0;
}