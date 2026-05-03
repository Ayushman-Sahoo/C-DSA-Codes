/* Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Find longest common prefix among given strings
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If array is empty
        if (strs.empty()) return "";

        // Take first string as initial prefix
        string prefix = strs[0];

        // Compare with remaining strings
        for (int i = 1; i < strs.size(); i++) {

            int j = 0;

            // Compare characters of prefix and current string
            while (j < prefix.length() && j < strs[i].length()
                   && prefix[j] == strs[i][j]) {
                j++;
            }

            // Update prefix to matched portion
            prefix = prefix.substr(0, j);

            // If prefix becomes empty → no common prefix
            if (prefix == "") return "";
        }

        return prefix;
    }
};

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;

    // Find and print result
    string result = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}