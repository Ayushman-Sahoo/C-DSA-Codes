#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, vector<int>& ans) {
    stack<int> s;

    ans.resize(arr.size());   // FIX: allocate memory

    int idx = arr.size() - 1;
    ans[idx] = -1;
    s.push(arr[arr.size() - 1]);

    for (idx = idx - 1; idx >= 0; idx--)
    {
        int curr = arr[idx];

        while (!s.empty() && s.top() <= curr)
        {
            s.pop();
        }

        if (s.empty()) {
            ans[idx] = -1;
        }
        else {
            ans[idx] = s.top();
        }

        s.push(curr);
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums1(n);
    vector<int> ans;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    vector<int> result = nextGreaterElement(nums1, ans);

    cout << "Next Greater Elements: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}