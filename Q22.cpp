/* 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int open, int close, int n,
               string current,
               vector<string>& ans) {

        // Base case
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(open + 1, close, n,
                  current + "(",
                  ans);
        }

        // Add closing bracket
        if (close < open) {
            solve(open, close + 1, n,
                  current + ")",
                  ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    vector<string> result = obj.generateParenthesis(n);

    cout << "Valid Parentheses:\n";

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}