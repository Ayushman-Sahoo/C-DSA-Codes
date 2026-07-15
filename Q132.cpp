/*132. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:
Input: s = "a"
Output: 0
Example 3:
Input: s = "ab"
Output: 1
Constraints:
1 <= s.length <= 2000
s consists of lowercase English letters only.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);

        // Worst case: cut before every character
        for (int i = 0; i <= n; i++)
            dp[i] = i - 1;

        for (int mid = 0; mid < n; mid++) {

            // Odd length palindromes
            for (int l = mid, r = mid; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
            }

            // Even length palindromes
            for (int l = mid, r = mid + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution obj;
    string s;

    cin >> s;

    cout << obj.minCut(s) << endl;

    return 0;
}