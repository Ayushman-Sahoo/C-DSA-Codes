#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int countDistinct(vector<int> arr) {
    unordered_set<int> s;

    for(int i = 0; i < arr.size(); i++) {
        s.insert(arr[i]);
    }

    for(int num : s) {
        cout << num << " ";
    }
     
    return s.size();
}

int main() {
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
  
    cout << "Number of distinct elements: " << countDistinct(arr) << endl;
    return 0;
}