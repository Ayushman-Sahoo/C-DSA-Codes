#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    int n;
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    } 
    int find(int u) {
        if(parent[u] == u) {
            return u;
        }

        return parent[u] = find(parent[u]);  // path compression
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
    void getInfo() {
        for(int i = 0; i < n; i++) {
            cout << parent[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++) {
            cout << rank[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++) {
            cout << size[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DisjointSet dj(6);

    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;

    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);

    cout << dj.find(2) << endl;

    dj.unionByRank(0, 4);

    // 🔥 print all arrays
    dj.getInfo();
}