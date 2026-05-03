/*   Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merged;
        int i = 0, j = 0;

        // Merge both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        int total = merged.size();

        // If total length is odd
        if (total % 2 == 1)
            return merged[total / 2];

        // If total length is even
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
};

int main() {
    Solution sol;

    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median = " << median << endl;

    return 0;
}