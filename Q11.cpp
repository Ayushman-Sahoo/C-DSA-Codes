/*  Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1
Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104*/

#include <iostream>     
#include <vector>       
#include <algorithm>    
using namespace std;

class Solution {
public:
    // Function to find maximum water container
    int maxArea(vector<int>& height) {

        int left = 0;                      // left pointer (start of array)
        int right = height.size() - 1;     // right pointer (end of array)

        int maxWater = 0;                  // stores maximum area found

        // Loop until both pointers meet
        while (left < right) {

            // Find smaller height (container height depends on smaller wall)
            int h = min(height[left], height[right]);

            // Calculate width between two pointers
            int w = right - left;

            // Calculate current area and update maximum if needed
            maxWater = max(maxWater, h * w);

            // Move pointer pointing to smaller height
            // because only that can possibly increase area
            if (height[left] < height[right]) {
                left++;   // move left pointer forward
            } else {
                right--;  // move right pointer backward
            }
        }

        return maxWater;
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> height(n);   
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];    
    }

    Solution obj;   
    cout << "Maximum water: " << obj.maxArea(height) << endl;

    return 0;   
}