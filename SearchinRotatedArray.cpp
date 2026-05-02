#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If target found
        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1; // target not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (rotated sorted array):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int result = searchRotated(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result;
    else
        cout << "Target not found";

    return 0;
}