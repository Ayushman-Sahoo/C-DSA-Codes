// Climbing Stairs
// Recursive Approach
/*#include <iostream>
#include <vector>
using namespace std;

int countWaysRec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return countWaysRec(n - 1) + countWaysRec(n - 2);
}

int main() {
    int n = 4; // 5

    cout << countWaysRec(n) << endl;

    return 0;
}*/
/*#include <iostream>
#include <vector>
using namespace std;

int countWaysRec(int n, vector<int>& dp) {
    if (n == 0 || n == 1) {
        return 1;
    }

    // if already calculated
    if (dp[n] != -1) {
        return dp[n];
    }

    // store result in dp
    return dp[n] = countWaysRec(n - 1, dp) + countWaysRec(n - 2, dp);
}

int main() {
    int n = 4; // 5

    // initialize dp with -1
    vector<int> dp(n + 1, -1);

    cout << countWaysRec(n, dp) << endl;

    return 0;
}*/

// Tabulation Approach
/*#include <iostream>
#include <vector>
using namespace std;

int countWaysTab(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 4; // 5

    cout << countWaysTab(n) << endl;

    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int countWaysTab(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n = 4; // 7

    cout << countWaysTab(n) << endl;

    return 0;
}