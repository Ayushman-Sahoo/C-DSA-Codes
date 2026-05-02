#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void maxAreaHistogram(vector<int> height) {

    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    // ---------------- Next Smaller Left ----------------
    nsl[0] = -1;
    s.push(0);

    for(int i = 1; i < n; i++) {
        int curr = height[i];

        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }

        s.push(i);
    }

    // Clear stack
    while(!s.empty()) {
        s.pop();
    }

    // ---------------- Next Smaller Right ----------------
    s.push(n - 1);
    nsr[n - 1] = n;

    for(int i = n - 2; i >= 0; i--) {
        int curr = height[i];

        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }

        s.push(i);
    }

    // ---------------- Calculate Max Area ----------------
    int maxArea = 0;

    for(int i = 0; i < n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;

        maxArea = max(area, maxArea);
    }

    cout << "Max area of histogram : " << maxArea << endl;
}

int main() {

    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    maxAreaHistogram(height);

    return 0;
}