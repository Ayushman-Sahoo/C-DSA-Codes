/*67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";      // Stores the final binary sum
        int i = a.length() - 1;  // Pointer for string a
        int j = b.length() - 1;  // Pointer for string b
        int carry = 0;           // Stores the carry

        // Continue until both strings and carry are processed
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add current digit from a
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Add current digit from b
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Store the current binary digit
            result += (sum % 2) + '0';

            // Update carry
            carry = sum / 2;
        }

        // Reverse the result because it was built backwards
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    string a, b;

    cout << "Enter first binary number: ";
    cin >> a;

    cout << "Enter second binary number: ";
    cin >> b;

    Solution obj;
    string ans = obj.addBinary(a, b);

    cout << "Binary Sum: " << ans << endl;

    return 0;
}