/*128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:
Input: nums = [1,0,1,2]
Output: 3
Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;

    for (int num : st) {

        // Start only if num is the first element of a sequence
        if (st.find(num - 1) == st.end()) {

            int currentNum = num;
            int count = 1;

            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Longest Consecutive Sequence Length = "
         << longestConsecutive(nums);

    return 0;
}