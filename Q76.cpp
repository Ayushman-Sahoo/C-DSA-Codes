/*76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    vector<int> freq(128, 0);

    for (char c : t) {
        freq[c]++;
    }

    int left = 0, right = 0;
    int count = t.size();
    int minLen = INT_MAX;
    int start = 0;

    while (right < s.size()) {
        if (freq[s[right]] > 0) {
            count--;
        }
        freq[s[right]]--;
        right++;

        while (count == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            freq[s[left]]++;
            if (freq[s[left]] > 0) {
                count++;
            }
            left++;
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);

    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}