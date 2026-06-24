/*84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:

Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int ans = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            ans = max(ans, h * width);
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "Largest Rectangle Area = " << largestRectangleArea(heights) << endl;

    return 0;
}