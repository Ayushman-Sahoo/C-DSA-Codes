/* Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 
Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans)
    {
        // If target becomes 0, store the combination
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        // Traverse candidates
        for(int i = index; i < candidates.size(); i++)
        {
            // Skip if number is greater than target
            if(candidates[i] > target)
                continue;

            // Choose the current number
            temp.push_back(candidates[i]);

            // Recursive call
            // i is used again because same number can be reused
            solve(i, candidates, target - candidates[i], temp, ans);

            // Backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};

int main() {

    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "\nCombinations are:\n";

    for(auto vec : result)
    {
        cout << "[ ";

        for(int num : vec)
        {
            cout << num << " ";
        }

        cout << "]\n";
    }

    return 0;
}