#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
    {
      int minIndex = i;
      for (int j = i + 1; j < n; j++) {
          if (arr[j] < arr[minIndex]) {  // Find the smallest element
              minIndex = j;
          }
      }
      swap(arr[i], arr[minIndex]);   // Swap smallest with current position
    }
  }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}