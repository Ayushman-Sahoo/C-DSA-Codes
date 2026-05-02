/*Given two strings str1 and str2, return the minimum number of operations required to convert str1 into str2.

You are allowed to perform the following operations:

Insert a character
Delete a character
Replace a character
Examples:

Example 1:
Input:
str1 = "abc"
str2 = "ac"
Output:
1
Explanation: Delete 'b'.

Example 2:
Input:
str1 = "horse"
str2 = "ros"
Output:
3
Explanation:

Replace 'h' with 'r'
Delete 'r'
Delete 'e'*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // bottom-up DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int insertOp = dp[i][j-1];
                    int deleteOp = dp[i-1][j];
                    int replaceOp = dp[i-1][j-1];

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    Solution obj;
    int result = obj.minDistance(str1, str2);

    cout << "Minimum operations required: " << result << endl;

    return 0;
}