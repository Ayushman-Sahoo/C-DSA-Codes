/* ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:
Input: s = "A", numRows = 1
Output: "A"
Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If only one row or rows exceed string length, return original string
        if (numRows == 1 || numRows >= s.length())
            return s;

        // Create a container for each row
        vector<string> rows(numRows);

        int currRow = 0;        // Track current row
        bool goingDown = false; // Direction flag

        // Traverse each character in the string
        for (char c : s) {
            rows[currRow] += c;  // Add character to current row

            // Change direction when we reach top or bottom row
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            // Move up or down
            currRow += goingDown ? 1 : -1;
        }

        string result;

        // Combine all rows to form final answer
        for (string row : rows)
            result += row;

        return result;
    }
};

int main() {
    string s;
    int numRows;

    cout << "Enter string: ";
    getline(cin, s); // Allows spaces in input

    cout << "Enter number of rows: ";
    cin >> numRows;

    Solution obj;

    // Display the zigzag converted string
    cout << "Zigzag Output: " << obj.convert(s, numRows) << endl;

    return 0;
}