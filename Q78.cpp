/*78. Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(curr);
        return;
    }

    // Exclude current element
    backtrack(idx + 1, nums, curr, ans);

    // Include current element
    curr.push_back(nums[idx]);
    backtrack(idx + 1, nums, curr, ans);

    // Backtrack
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    backtrack(0, nums, curr, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:\n";
    cout << "[\n";
    for (auto &subset : result) {
        cout << "  [";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}