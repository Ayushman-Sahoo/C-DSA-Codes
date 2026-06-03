// Recursion
/*#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mcmRec(vector<int> arr, int i, int j) {

    if(i == j) {
        return 0;
    }

    int ans = INT_MAX;

    for(int k = i; k < j; k++) {

        int cost1 = mcmRec(arr, i, k);
        int cost2 = mcmRec(arr, k + 1, j);

        int currCost = cost1 + cost2 +
                       (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, currCost);
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> arr(n + 1);

    cout << "Enter dimensions: ";
    for(int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum Cost = "
         << mcmRec(arr, 1, n);

    return 0;
}*/

// Memoization
/*#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mcmMemo(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {

    if (i == j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {

        int cost1 = mcmMemo(arr, i, k, dp);
        int cost2 = mcmMemo(arr, k + 1, j, dp);

        int currCost = cost1 + cost2 +
                       (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

int main() {

    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> arr(n + 1);

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << "Minimum Cost = "
         << mcmMemo(arr, 1, n, dp);

    return 0;
}*/

//Tabulation

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mcmTab(vector<int>& arr, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int currCost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {

    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> arr(n + 1);

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum Cost = "
         << mcmTab(arr, n);

    return 0;
}