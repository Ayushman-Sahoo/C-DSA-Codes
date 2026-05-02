#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // return -1 if not found
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; // array of size n

    // Taking array input
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    // Call function
    int result = linearSearch(arr, n, key);

    if (result != -1) {
        cout << "Element " << key << " found at position " << result + 1 << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }
    return 0;
}