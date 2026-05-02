#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "\nAll subarrays are:\n";
     // Outer loop: starting index
    for (int start = 0; start < n; start++) {
        // Inner loop: ending index
        for (int end = start; end < n; end++) {
            // Print elements from start to end
            cout << "[ ";
            for (int k = start; k <= end; k++) {
                cout << arr[k] << " ";
            }
            cout << "]\n";
        }
    }
  return 0;
}