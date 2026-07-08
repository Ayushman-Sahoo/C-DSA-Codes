/*115. Distinct Subsequences
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    dp[j + 1] += dp[j];
            }
        }

        return dp[m];
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "Number of distinct subsequences = "
         << obj.numDistinct(s, t) << endl;

    return 0;
}