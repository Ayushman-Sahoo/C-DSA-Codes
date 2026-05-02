/*Find if there is a subset of numbers which give sum equal to target.
nums[] = {4, 2, 7, 1, 3}
target sum = 7*/

#include <iostream>
#include <vector>
using namespace std;

bool targetSum(vector<int> nums, int target) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {

            if (nums[i - 1] <= j) {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]],
                               dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }

        }
    }

    // print dp table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][target] == target;
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 7;

    if (targetSum(nums, target)) {
        cout << "Subset found with the target sum." << endl;
    } else {
        cout << "No subset found with the target sum." << endl;
    }

    return 0;
}