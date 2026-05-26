/* Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 
Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1;
        int match = 0;

        while (i < s.size()) {

            // If characters match or pattern has '?'
            if (j < p.size() && 
               (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }

            // If pattern has '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }

            // Backtrack if previous '*' exists
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }

            // No match possible
            else {
                return false;
            }
        }

        // Skip remaining '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};

int main() {
    Solution obj;

    string s, p;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter pattern: ";
    cin >> p;

    if (obj.isMatch(s, p)) {
        cout << "Pattern matches the string" << endl;
    } else {
        cout << "Pattern does not match the string" << endl;
    }

    return 0;
}