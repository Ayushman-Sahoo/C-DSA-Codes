/* Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans)
    {
        // If target becomes 0
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++)
        {
            // Skip duplicate elements
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Stop if element is greater than target
            if(candidates[i] > target)
                break;

            // Choose current element
            temp.push_back(candidates[i]);

            // Recursive call
            solve(i + 1, candidates, target - candidates[i], temp, ans);

            // Backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        // Sort array
        sort(candidates.begin(), candidates.end());

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

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

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