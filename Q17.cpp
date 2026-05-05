/* 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;

        function<void(int, string)> backtrack = [&](int index, string current) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            string letters = mapping[digits[index] - '0'];

            for (char ch : letters) {
                backtrack(index + 1, current + ch);
            }
        };

        backtrack(0, "");
        return result;
    }
};

int main() {
    Solution obj;

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> ans = obj.letterCombinations(digits);

    cout << "Output: ";
    for (string s : ans) {
        cout << s << " ";
    }

    return 0;
}