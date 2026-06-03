/*55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        // Farthest index we can reach so far
        int farthestReach = 0;

        for (int currentIndex = 0; currentIndex < nums.size(); currentIndex++) {

            // If current index is beyond our reach,
            // we are stuck
            if (currentIndex > farthestReach) {
                return false;
            }

            // Update the farthest reachable index
            farthestReach = max(farthestReach,
                                currentIndex + nums[currentIndex]);

            // If we can reach the last index
            if (farthestReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    if (obj.canJump(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}