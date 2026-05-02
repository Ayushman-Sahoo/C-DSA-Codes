/*Given two strings str1 and str2, find the length of the longest common substring.
str1 = "abcde"
str2 = "abgce"

Output:
2                   "ab is the longest common substring" */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubstring(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}

int  main() {
    string str1 = "abcde";
    string str2 = "abgce";

    cout << "Length of longest common substring: "
         << longestCommonSubstring(str1, str2);

    return 0;
} 