/* Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 
Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {

    // If any number is 0
    if(num1 == "0" || num2 == "0")
        return "0";

    int n = num1.size();
    int m = num2.size();

    vector<int> result(n + m, 0);

    // Multiply digits from right to left
    for(int i = n - 1; i >= 0; i--) {

        for(int j = m - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;

            result[i + j] += sum / 10;
        }
    }

    // Convert vector into string
    string ans = "";

    for(int num : result) {

        // Skip leading zeros
        if(!(ans.empty() && num == 0)) {
            ans += (num + '0');
        }
    }

    return ans;
}

int main() {

    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Product = " << multiply(num1, num2);

    return 0;
}