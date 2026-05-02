#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> arr, int target, int i = 0) {
    // Base case
    if (i == arr.size()) {
        return -1;
    }

    // If found
    if (arr[i] == target) {
        return i;
    }

    // Recursive call
    return firstOccurance(arr, target, i + 1);
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

    int result = firstOccurance(arr, target);

    if (result != -1) {
        cout << "First occurrence of " << target << " is at index " << result << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
//loop
/*#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> &v, int key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            return i;   // first occurrence index
        }
    }
    return -1;  // not found
}

int main() {
    vector<int> v = {1, 2, 3, 2, 4, 2};
    int key = 2;

    int index = firstOccurrence(v, key);

    if (index != -1)
        cout << "First occurrence at index: " << index;
    else
        cout << "Element not found";

    return 0;
}
*/