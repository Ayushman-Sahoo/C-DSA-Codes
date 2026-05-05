/*Given an integer n, find the number of structurally unique Binary Search Trees (BSTs) that can be formed using values from 1 to n.

📌 Problem Description

A Binary Search Tree (BST) is defined such that:

Left subtree contains only nodes with values less than the root.
Right subtree contains only nodes with values greater than the root.

You need to count all possible BSTs that can be formed with n distinct nodes.

Example 1:

Input: n = 2
Output: 2

Example 2:

Input: n = 3
Output: 5

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    int result = obj.numTrees(n);

    cout << "Number of unique BSTs: " << result << endl;

    return 0;
}