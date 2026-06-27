/*90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(int index, vector<int>& nums) {

    ans.push_back(temp);

    for (int i = index; i < nums.size(); i++) {

        if (i > index && nums[i] == nums[i - 1])
            continue;

        temp.push_back(nums[i]);

        solve(i + 1, nums);

        temp.pop_back();
    }
}

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    solve(0, nums);

    cout << "\nSubsets are:\n";

    for (auto subset : ans) {

        cout << "[ ";

        for (int x : subset)
            cout << x << " ";

        cout << "]" << endl;
    }

    return 0;
}