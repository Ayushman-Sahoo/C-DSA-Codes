/* 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Find 3 numbers whose sum is closest to target
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Initialize closest sum using first three elements
        int closestSum = nums[0] + nums[1] + nums[2];

        // Step 2: Fix one element
        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            // Step 3: Two pointer approach
            while (left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closest sum if this is nearer to target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // If exact match, return immediately
                if (currentSum == target) {
                    return currentSum;
                }
                else if (currentSum < target) {
                    left++;   // increase sum
                }
                else {
                    right--;  // decrease sum
                }
            }
        }

        return closestSum;
    }
};

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    // Call function and print result
    cout << "Closest Sum: " << obj.threeSumClosest(nums, target) << endl;

    return 0;
}