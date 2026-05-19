/*  Count and Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

Constraints:

1 <= n <= 30
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string countAndSay(int n) {

        string result = "1";

        // Generate terms from 2 to n
        for (int i = 2; i <= n; i++) {

            string temp = "";
            int count = 1;

            for (int j = 0; j < result.length(); j++) {

                // Count consecutive same characters
                while (j + 1 < result.length() &&
                       result[j] == result[j + 1]) {

                    count++;
                    j++;
                }

                // Add count and character
                temp += to_string(count);
                temp += result[j];

                // Reset count
                count = 1;
            }

            result = temp;
        }

        return result;
    }
};

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Count and Say Sequence: ";
    cout << obj.countAndSay(n);

    return 0;
}