/*60. Permutation Sequence
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

Constraints:

1 <= n <= 9
1 <= k <= n!
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> numbers;
    int fact = 1;

    // Calculate (n-1)! and store numbers 1 to n
    for (int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    string ans = "";

    // Convert k to 0-based indexing
    k--;

    while (!numbers.empty()) {

        int index = k / fact;
        ans += to_string(numbers[index]);

        // Remove the used number
        numbers.erase(numbers.begin() + index);

        if (numbers.empty()) {
            break;
        }

        k = k % fact;
        fact = fact / numbers.size();
    }

    return ans;
}

int main() {
    int n, k;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    cout << "\nThe " << k << "th permutation is: "
         << getPermutation(n, k) << endl;

    return 0;
}