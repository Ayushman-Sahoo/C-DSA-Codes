/* 46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {

        // Base Case
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Generate permutations
        for(int i = index; i < nums.size(); i++) {

            // Swap current element
            swap(nums[index], nums[i]);

            // Recursive call
            solve(nums, ans, index + 1);

            // Backtracking
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        solve(nums, ans, 0);

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<vector<int>> result = obj.permute(nums);

    cout << "\nAll Permutations are:\n";

    for(auto perm : result) {

        cout << "[ ";

        for(int num : perm) {
            cout << num << " ";
        }

        cout << "]\n";
    }

    return 0;
}