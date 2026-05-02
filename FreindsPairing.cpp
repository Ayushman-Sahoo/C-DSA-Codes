//Find total number of ways in which n friends can remain single or can be paired.
//Each friend can be paired only once.
#include <iostream>
using namespace std;

int friendsPairing(int n) {
    // base case
    if (n == 1 || n == 2)
        return n;

    // recursive case
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    cout << "Total ways: " << friendsPairing(n);
    return 0;
}
// Dynamic Programming (Memoization)
/*#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    int dp[100];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    cout << "Total ways: " << dp[n];
    return 0;
}*/