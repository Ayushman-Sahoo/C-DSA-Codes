/*77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

Constraints:

1 <= n <= 20
1 <= k <= n
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int start, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(i + 1, n, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};

int main() {
    int n, k;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    vector<vector<int>> result = sol.combine(n, k);

    cout << "Combinations are:\n";
    for (const auto &comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}