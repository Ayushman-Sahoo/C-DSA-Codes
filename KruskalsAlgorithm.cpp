#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    vector<int> parent, rank;

    Graph(int V) {
        this->V = V;
        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i < V; i++) {
            parent[i] = i;
        } 
    }

    int find(int u) {
        if(parent[u] == u) {
            return u;
        }

        return parent[u] = find(parent[u]);
    }

    int unionByRank(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_u == ulp_v) {
            return 0;
        }

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        return 1;
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    int kruskalMST() {
        int mincost = 0;
        int count = 0;
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.wt < b.wt;
        });

        int mstWt = 0;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int wt = edges[i].wt;

            if(unionByRank(u, v)) {
                mstWt += wt;
            }
        }

        return mstWt;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    cout << graph.kruskalMST();

    return 0;
}