//Recursion 
/*#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n){
  if (n == 0 || W == 0)
  {
    return 0;
  }
  
    int itemWt = wt[n - 1];
int itemVal = val[n - 1];

if (itemWt <= W) { // valid wt
    // include
    int ans1 = knapsack(W - itemWt, wt, val, n - 1) + itemVal;

    // exclude
    int ans2 = knapsack(W, wt, val, n - 1);

    return max(ans1, ans2);
} else {
    // exclude
    return knapsack(W, wt, val, n - 1);
}
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    cout << knapsack(W, wt, val, n) << endl;
    return 0;
}*/

//Memoization
#include<iostream>
#include<vector>
using namespace std;

int knapsackMemo(vector<int> &val, vector<int> &wt, int W, int n, vector<vector<int>> &dp) {
    // base case
    if (n == 0 || W == 0) return 0;

    // already computed
    if (dp[n][W] != -1) return dp[n][W];

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemWt <= W) {
        // include or exclude
        int include = itemVal + knapsackMemo(val, wt, W - itemWt, n - 1, dp);
        int exclude = knapsackMemo(val, wt, W, n - 1, dp);

        dp[n][W] = max(include, exclude);
    } else {
        // exclude only
        dp[n][W] = knapsackMemo(val, wt, W, n - 1, dp);
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
     }    
    return dp[n][W];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int W = 7;
    int n = val.size();

    // dp initialized with -1
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << knapsackMemo(val, wt, W, n, dp) << endl;

    return 0;
}

//Tabulation
/*#include<iostream>
#include<vector>
using namespace std;
int knapsackTab(vector<int> val, vector<int> wt, int W, int n) { // O(n*W)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int itemWt = wt[i - 1];
            int itemVal = val[i - 1];

            if (itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i - 1][j - itemWt], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[n][W];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    cout << knapsackTab(val, wt, W, n) << endl;
    return 0;
}*/