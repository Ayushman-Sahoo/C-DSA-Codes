/*Given an array of integers arr[], find the length of the longest increasing subsequence.
Example:
Input:
arr[] = {50, 3, 10, 7, 40, 80}

Output:
4

Explanation:
The longest increasing subsequence is {3, 7, 40, 80}
(or {3, 10, 40, 80}), so length = 4.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int LIS(vector<int> arr) {
    // Step 1: Remove duplicates
    unordered_set<int> s(arr.begin(), arr.end());

    // Step 2: Put into vector and sort
    vector<int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end());

    // Step 3: Apply LCS
    int n = arr.size();
    int m = arr2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (arr[i - 1] == arr2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    return dp[n][m];
}

int main() {
    vector<int> arr = {50, 3, 10, 7, 40, 80};

    cout << "Length of LIS: " << LIS(arr);

    return 0;
}