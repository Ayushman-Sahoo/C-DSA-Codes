/*Indian Coins

We are given an infinite supply of denominations
[1, 2, 5, 10, 20, 50, 100, 500, 2000].

Find the minimum number of coins to make change for a value V.

Example 1:

V = 121
Answer = 3 (100 + 20 + 1)

Example 2:

V = 590
Answer = 4 (500 + 50 + 20 + 20)*/

#include <iostream>
#include <vector>
using namespace std;

int getMinChange(vector<int> coins, int V) {
    int ans = 0;
    int n = coins.size();

    for(int i = n - 1; i >= 0 && V > 0; i--) {
        if(V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];   // reduce the remaining value
        }
    }
    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 590;

    cout << getMinChange(coins, V);

    return 0;
}