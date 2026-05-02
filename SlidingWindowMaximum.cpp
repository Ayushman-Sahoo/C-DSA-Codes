/*Sliding Window Maximum
You are given an array of integers and an integer K representing the size of a sliding window.
Your task is to find the maximum element in every subarray (window) of size K as the window moves from the left to the right of the array.
At each step, the window slides one position to the right, and you must record the maximum value in that window.
Example
Array:
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
K = 3
Subarrays of size 3:
[1,2,3]
[2,3,4]
[3,4,5]
[4,5,6]
[5,6,7]
[6,7,8]
[7,8,9]
[8,9,10]*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void slidingWindowMax(vector<int> arr, int K) {
    priority_queue<pair<int, int>> pq;

    //1st window
    for(int i=0; i<K; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "output : " << pq.top().first << " ";

    for(int i=K; i<arr.size(); i++) {
        while(!pq.empty() && pq.top().second <= (i-K)) { //outside window
            pq.pop();
        }

        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }

    cout << endl;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
  int k = 3;

  slidingWindowMax(arr, k);
  return 0;
}

/*#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++) {

        // Remove indices that are out of this window
        if(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from back
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Store result when first window is complete
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;

    vector<int> ans = slidingWindowMax(arr, k);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}*/