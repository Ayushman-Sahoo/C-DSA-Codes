/*69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
Constraints:

0 <= x <= 2^31 - 1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long long left = 1, right = x;
        int ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;       // Store the possible answer
                left = mid + 1;  // Search in the right half
            }
            else {
                right = mid - 1; // Search in the left half
            }
        }

        return ans;
    }
};

int main() {
    int x;

    cout << "Enter a non-negative integer: ";
    cin >> x;

    Solution obj;
    cout << "Square root (rounded down): " << obj.mySqrt(x) << endl;

    return 0;
}