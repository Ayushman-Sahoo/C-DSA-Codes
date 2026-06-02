/* 50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn). 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/2^2 = 1/4 = 0.25
 
Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= xn <= 10^4
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    long long power = n;  // To handle INT_MIN

    if (power < 0) {
        x = 1 / x;
        power = -power;
    }

    double result = 1.0;

    while (power > 0) {

        // If power is odd
        if (power % 2 == 1) {
            result *= x;
        }

        x *= x;        // Square the base
        power /= 2;    // Divide power by 2
    }

    return result;
}

int main() {
    double x;
    int n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    double answer = myPow(x, n);

    cout << "Result = " << answer << endl;

    return 0;
}