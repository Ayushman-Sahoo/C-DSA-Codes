//Leet Code Number 1584
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        // (weight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // (wt, u)
        int src = 0;
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int minCost = 0;

        while (pq.size() > 0) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();   // ✅ IMPORTANT FIX

            if (!mst[u]) {
                mst[u] = true;
                minCost += cost;

                for (int v = 0; v < V; v++) {
                    if (u != v && !mst[v]) {   // small correction
                        int wt = abs(points[u][0] - points[v][0]) 
                               + abs(points[u][1] - points[v][1]);

                        pq.push(make_pair(wt, v));
                    }
                }
            }
        }

        return minCost;
    }
};

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter x and y coordinates:\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution obj;
    int result = obj.minCostConnectPoints(points);

    cout << "Minimum Cost to Connect Points: " << result << endl;

    return 0;
}