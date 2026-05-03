/*  Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Constraints:
-231 <= x <= 231 - 1*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers and numbers ending with 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reversedHalf = 0;

        // Reverse only half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Check for even and odd length numbers
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
int main() {
    int x;
    cin >> x;

    Solution obj;
    if (obj.isPalindrome(x))
        cout << "true";
    else
        cout << "false";

    return 0;
}