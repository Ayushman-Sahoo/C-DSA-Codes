//recursion to check if an array is sorted
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int i) {
    // Base case
    if (i == n - 1) {
        return true;
    }

    // Check current and next element
    if (arr[i] > arr[i + 1]) {
        return false;
    }

    // Recursive call
    return isSorted(arr, n, i + 1);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr, n, 0))
        cout << "Array is sorted";
    else
        cout << "Array is NOT sorted";

    return 0;
}

//loop
/*
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    // Loop through array
    for (int i = 0; i < n - 1; i++) {
        // If any element is greater than next, not sorted
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSorted(arr, n))
        cout << "Array is sorted";
    else
        cout << "Array is NOT sorted";

    return 0;
}
*/