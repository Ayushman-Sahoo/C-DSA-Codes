/*Given an integer n, representing the number of pairs of upstrokes and downstrokes, find the total number of valid mountain ranges that can be formed.

📌 Rules
Each mountain range consists of n upstrokes (U) and n downstrokes (D).

At any point in the sequence:

The number of downstrokes must never exceed upstrokes.

The sequence must be balanced (i.e., total upstrokes = total downstrokes).

📥 Input

An integer n (number of pairs of strokes)

📤 Output

Total number of valid mountain ranges

📊 Example
Input: n = 3Output: 5
*/


#include <iostream>
#include <vector>

using namespace std;

int countMountainRanges(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There is one way to form a mountain range with 0 pairs (the empty range)

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j]; // C(i) += C(j) * C(i-1-j)
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of pairs of strokes (n): ";
    cin >> n;

    int result = countMountainRanges(n);
    cout << "Total number of valid mountain ranges: " << result << endl;

    return 0;
}
