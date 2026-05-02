//Recursion
#include <iostream>
using namespace std;
int tilingProblem(int n) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive calls  vertical (n-1) and horizontal placement (n-2)
    return tilingProblem(n - 1) + tilingProblem(n - 2);
}
int main() {
    int n;
    cout << "Enter the length of the floor (n): ";
    cin >> n;
    int ways = tilingProblem(n);
    cout << "Number of ways to tile a 2 x " << n << " floor: " << ways << endl;
    return 0;
}
// Dynamic Programming (Memoization)
/*#include <iostream>
#include <vector>
using namespace std;

int tilingDP(int n, vector<int> &dp) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1;
    }

    // If already calculated
    if (dp[n] != -1) {
        return dp[n];
    }

    // Store and return
    dp[n] = tilingDP(n - 1, dp) + tilingDP(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Total ways: " << tilingDP(n, dp);
    return 0;
}*/