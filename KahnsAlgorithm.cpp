#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int V;
list<int>* l;

void calcIndegree(vector<int> &indeg) {   // fixed pass by reference
    for(int u = 0; u < V; u++) {
        list<int> neighbors = l[u];
        for(int v : neighbors) { // u ---> v
            indeg[v]++;
        }
    }
}

void topoSort2() { // kahn's algo
    vector<int> indeg(V, 0);
    calcIndegree(indeg);
    queue<int> q;

    // 0 indeg nodes -> starting point
    for(int i = 0; i < V; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(q.size() > 0) {
        int curr = q.front();
        q.pop();

        cout << curr << " "; // to show result

        list<int> neighbors = l[curr];
        for(int v : neighbors) {
            indeg[v]--;   // fixed
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    V = 6;
    l = new list<int>[V];

    l[5].push_back(2);
    l[5].push_back(0);
    l[4].push_back(0);
    l[4].push_back(1);
    l[2].push_back(3);
    l[3].push_back(1);

    topoSort2();

    return 0;
}