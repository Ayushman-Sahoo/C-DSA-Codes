/*#include <iostream>
using namespace std;

int main() {
    int n, key;

    // Step 1: Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Step 2: Input array elements (should be sorted for binary search)
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Step 4: Binary Search
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2; // to avoid overflow

        if (arr[mid] == key) {
            found = true;
            cout << "Element found at position: " << mid + 1 << endl; // position starts from 1
            break;
        } else if (arr[mid] < key) {
            left = mid + 1; // search in right half
        } else {
            right = mid - 1; // search in left half
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}*/

// Recursive Approach
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    // Base case: element not found
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2; // to avoid overflow

    // Element found
    if (arr[mid] == key) {
        return mid;
    }
    // Search in the right half
    else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, right, key);
    }
    // Search in the left half
    else {
        return binarySearch(arr, left, mid - 1, key);
    }
}

int main() {
    int n, key;

    // Step 1: Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Step 2: Input array elements (should be sorted for binary search)
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Input the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Step 4: Binary Search
    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at position: " << result + 1 << endl; // position starts from 1
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}