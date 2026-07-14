/*131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;
vector<string> path;

bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void backtrack(string &s, int start) {
    if (start == s.size()) {
        ans.push_back(path);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1);
            path.pop_back();
        }
    }
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    backtrack(s, 0);

    cout << "\nPalindrome Partitions:\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (auto &str : v)
            cout << "\"" << str << "\" ";
        cout << "]\n";
    }

    return 0;
}