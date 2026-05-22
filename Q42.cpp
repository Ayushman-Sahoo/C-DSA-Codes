/* 42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9*/
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& h) {

    int n = h.size();

    int lmx = 0, rmx = 0;
    int l = 0, r = n - 1;

    int ans = 0;

    while (l <= r) {

        // Move the smaller height side
        if (h[l] <= h[r]) {

            lmx = max(lmx, h[l]);

            ans += lmx - h[l];

            l++;
        }
        else {

            rmx = max(rmx, h[r]);

            ans += rmx - h[r];

            r--;
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> h(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int water = trap(h);

    cout << "Total trapped water = " << water;

    return 0;
}