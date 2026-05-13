/*  28. Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n - m; i++) {

            int j;

            for(j = 0; j < m; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if(j == m) {
                return i;
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    string haystack, needle;

    cout << "Enter haystack string: ";
    cin >> haystack;

    cout << "Enter needle string: ";
    cin >> needle;

    int result = obj.strStr(haystack, needle);

    cout << "First occurrence index: " << result << endl;

    return 0;
}