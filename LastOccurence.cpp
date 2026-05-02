//Recursion
#include <iostream>
#include <vector>
using namespace std;
int lastOccurrence(const vector<int>& arr, int target, int i = 0){
  // Base case
    if (i == arr.size()) {
        return -1;
    }
    // Recursive call
    int restIndex = lastOccurrence(arr, target, i + 1);
    // If found later, return that
    if (restIndex != -1) {
        return restIndex;
    }

    // Otherwise check current index
    if (arr[i] == target) {
        return i;
    }

    return -1;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int result = lastOccurrence(arr, target);

    if (result != -1) {
        cout << "Last occurrence of " << target << " is at index " << result << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
//Loop
/*#include <iostream>
#include <vector>
using namespace std;

int lastOccurrence(vector<int> &arr, int target) {
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == target) {
            return i;   // last occurrence index
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 2};
    int target = 2;

    int result = lastOccurrence(arr, target);

    if (result != -1)
        cout << "Last occurrence at index: " << result;
    else
        cout << "Element not found";

    return 0;
}*/