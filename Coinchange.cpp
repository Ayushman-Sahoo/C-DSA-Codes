/*Question: Coin Change
Given an array of coin denominations coins[] = {1, 2, 5} and a target amount amount = 5, return the number of different combinations of coins that can make up the amount.
You have an unlimited supply of each coin.

Example:
Input:
coins[] = {1, 2, 5}
amount = 5

Output:
4*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // If amount = 0, only 1 way (choose nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // If coin can be used
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Print DP Table
        cout << "DP Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n][amount];
    }
};

int main() {
    Solution obj;

    int amount = 5;
    vector<int> coins = {1, 2, 5};

    int ans = obj.change(amount, coins);

    cout << "\nNumber of combinations = " << ans << endl;

    return 0;
}