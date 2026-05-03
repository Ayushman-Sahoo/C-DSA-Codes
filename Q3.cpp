/*  Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  This program finds the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Array to store last index of each character
        vector<int> last(256, -1);

        int start = 0;   // start index of substring
        int maxLen = 0;  // stores maximum length

        for (int i = 0; i < s.length(); i++) {

            // If character already appeared, move start
            if (last[s[i]] >= start) {
                start = last[s[i]] + 1;
            }

            // Update last index of current character
            last[s[i]] = i;

            // Calculate current length
            int currentLen = i - start + 1;

            // Update maximum length
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution obj;
    string s;

    // Input string
    cout << "Enter the string: ";
    getline(cin, s);

    // Function call
    int result = obj.lengthOfLongestSubstring(s);

    // Output result
    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}