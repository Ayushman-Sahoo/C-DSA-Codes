/*#include <iostream>
#include <vector>
using namespace std;
vector<int> pairSumBrute(vector<int>& arr, int target){
    vector<int> result;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result; // return empty if no pair found
}
int main(){
  vector<int> arr = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = pairSumBrute(arr, target);
  if(!result.empty()){  
      cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
  } else {
      cout << "No pair found." << endl;
  }
}*/
/*#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumBrute(vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // return empty if no pair found
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = pairSumBrute(arr, target);
    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}*/

//2pointer approach
#include <iostream>
#include <vector> 
using namespace std;
vector<int> pairSumTwoPointer(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            return {left, right};
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; // return empty if no pair found
}
int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = pairSumTwoPointer(arr, target);
    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}