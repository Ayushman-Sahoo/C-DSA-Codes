/* 47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& temp,
               vector<bool>& used) {

        // If permutation is complete
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Skip already used element
            if(used[i])
                continue;

            // Skip duplicate elements
            if(i > 0 &&
               nums[i] == nums[i - 1] &&
               used[i - 1] == false)
                continue;

            // Take current element
            used[i] = true;

            temp.push_back(nums[i]);

            // Recursive call
            solve(nums, ans, temp, used);

            // Backtracking
            temp.pop_back();

            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Sort array to handle duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        vector<int> temp;

        vector<bool> used(nums.size(), false);

        solve(nums, ans, temp, used);

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

    vector<vector<int>> result = obj.permuteUnique(nums);

    cout << "\nUnique Permutations are:\n";

    for(auto perm : result) {

        cout << "[ ";

        for(int num : perm) {
            cout << num << " ";
        }

        cout << "]\n";
    }

    return 0;
}