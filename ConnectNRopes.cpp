/*Connect N Ropes
You are given N ropes with different lengths.
The cost to connect two ropes is equal to the sum of their lengths.
Your task is to connect all the ropes into a single rope such that the total cost is minimum.
Example:
Rope lengths = {4, 3, 2, 6}*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ConnectNRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); // Min-heap
    int totalCost = 0;

    while(pq.size() > 1) {
        int first = pq.top(); 
        pq.pop();
        int second = pq.top(); 
        pq.pop();
        int cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }

    return totalCost;
}

int main(){
  vector<int> ropes = {4, 3, 2, 6};
  cout << "Minimum cost to connect all ropes: " << ConnectNRopes(ropes) << endl;
  return 0;
}