#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarrayCountWithK(vector<int> arr, int K) {
    unordered_map<int, int> m; // <sum, count>
    m[0] = 1;

    int sum = 0;
    int ans = 0;

    for(int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        if(m.count(sum - K)) {
            ans += m[sum - K];
        }

        if(m.count(sum)) {
            m[sum]++;
        } 
        else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = 3;
    cout << "Count of subarrays with sum " << k << " is: "
         << subarrayCountWithK(arr, k) << endl;
    return 0;
}