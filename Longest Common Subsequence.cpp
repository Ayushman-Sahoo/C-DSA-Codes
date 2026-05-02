/*Given two strings:

str1 = "abcdge"
str2 = "abedg"

A subsequence is formed by deleting zero or more characters from a string without changing the order of the remaining characters. */


// Recursive approach (Exponential time complexity)
/*#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string str1, string str2) {
    if (str1.size() == 0 || str2.size() == 0)
    {
      return 0;
    }
      

    int n = str1.size();
    int m = str2.size();

    if (str1[n-1] == str2[m-1]) {
        return 1 + longestCommonSubsequence(str1.substr(0, n-1), str2.substr(0, m-1));
    }
    else {
        int ans1 = longestCommonSubsequence(str1.substr(0, n-1), str2);
        int ans2 = longestCommonSubsequence(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << "Length of longest common subsequence: " << longestCommonSubsequence(str1, str2);

    return 0;
}*/


// Memoization approach (Top-down)
/*#include <iostream>
#include <vector>

using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>> &dp) {
    // Base case
    if (i == 0 || j == 0)
        return 0;

    // Already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    // Match case
    if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + solve(str1, str2, i - 1, j - 1, dp);
    }
    else {
        int ans1 = solve(str1, str2, i - 1, j, dp);
        int ans2 = solve(str1, str2, i, j - 1, dp);
        dp[i][j] = max(ans1, ans2);
    }

    return dp[i][j];
}

int longestCommonSubsequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // DP table initialized with -1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(str1, str2, n, m, dp);
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << "Length of longest common subsequence: "
         << longestCommonSubsequence(str1, str2);

    return 0;
}*/


// Tabulation approach (Bottom-up)
#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << "Length of longest common subsequence: "
         << longestCommonSubsequence(str1, str2);

    return 0;
}