/* 32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 
Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        // Push -1 as base index
        st.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {

            // If opening bracket
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                // Pop previous opening bracket
                st.pop();

                // If stack becomes empty
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    // Calculate valid length
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    int ans = obj.longestValidParentheses(s);

    cout << "Longest Valid Parentheses Length = " << ans << endl;

    return 0;
}