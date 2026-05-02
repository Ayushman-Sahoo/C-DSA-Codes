/*Given a string text and a pattern pattern, determine if the pattern matches the entire text.
The pattern can include the following special characters:

'?' → Matches any single character

'*' → Matches any sequence of characters (including the empty sequence)

Your Task
Return true if the pattern matches the entire text, otherwise return false.

Examples:
Example 1:
Input:
Text = "baaabab"
Pattern = "**ba****ab*"
Output:
true

Example 2:
Input:
Text = "baaabab"
Pattern = "a*ab"
Output:
false
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // base case
        dp[0][0] = true;

        // pattern vs empty text
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            } else {
                dp[0][j] = false;
            }
        }

        // bottom-up manner fill DP (YOUR CODE ADDED)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(t[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        for (int i = 0; i <= n+1; i++)
        {
          for (int j = 0; j < m+1; j++)
          {
            cout << dp[i][j] << " ";
          }
          cout << endl;
        }
        
        return dp[n][m];
    }
};

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    Solution obj;
    bool result = obj.isMatch(text, pattern);

    if(result)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}