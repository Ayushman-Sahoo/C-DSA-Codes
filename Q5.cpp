/*   Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0;      // starting index of longest palindrome
        int maxLen = 1;     // length of longest palindrome

        // Loop through each character as a center
        for (int i = 0; i < n; i++) {

            // -------- Odd length palindrome --------
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // -------- Even length palindrome --------
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        // Return longest palindrome substring
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter the string: ";
    cin >> s;   // works for letters & digits (no spaces)

    string result = obj.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}