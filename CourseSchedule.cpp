//For given courses & their pre-requisites, return if it is possible for finish them or not


#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>>& graph) {
    vis[src] = true;
    rec[src] = true;

    for (int i = 0; i < graph.size(); i++) {
        int u = graph[i][1];
        int v = graph[i][0];

        if (u == src) {
            if (!vis[v]) {
                if (isCycle(v, vis, rec, graph)) {
                    return true;
                }
            } else {
                if (rec[v]) {
                    return true;
                }
            }
        }
    }

    rec[src] = false; // fix
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& graph) {
    int V = numCourses;

    vector<bool> vis(V, false);
    vector<bool> rec(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (isCycle(i, vis, rec, graph)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> graph = {{1, 0}}; // example

    if (canFinish(numCourses, graph)) {
        cout << "Yes, can finish courses";
    } else {
        cout << "No, cycle detected";
    }

    return 0;
}