//loops-Brute Force Approach
/*
#include <iostream>
#include <vector>
using namespace std;

int largestSubWith0Sum(vector<int> arr) {
    int n = arr.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                int len = j - i + 1;
                if(len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << "Length of the largest subarray with sum 0 is: "
         << largestSubWith0Sum(arr) << endl;

    return 0;
}
*/


//Hash maps
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int largestSubWith0Sum(vector<int> arr) {
    unordered_map<int, int> m; // <sum, idx>
    int sum = 0;
    int ans = 0;

    for(int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        if(sum == 0)
            ans = j + 1;

        if(m.count(sum)) {
            int currLen = j - m[sum]; // j - idx
            ans = max(ans, currLen);
        }
        else {
            m[sum] = j;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << "Length of the largest subarray with sum 0 is: "
         << largestSubWith0Sum(arr) << endl;

    return 0;
}