#include <iostream>
#include <vector>
using namespace std;

// -------- MAX HEAPIFY (for Ascending Sort) --------
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Assume root is largest
    int left = 2*i + 1;       // Left child
    int right = 2*i + 2;      // Right child

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest); // Fix subtree
    }
}

// -------- MIN HEAPIFY (for Descending Sort) --------
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;        // Assume root is smallest
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest); // Fix subtree
    }
}

// -------- HEAP SORT ASCENDING --------
void heapSortAscending(vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// -------- HEAP SORT DESCENDING --------
void heapSortDescending(vector<int>& arr) {
    int n = arr.size();

    // Build Min Heap
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {1,4,2,5,3};
    vector<int> arr2 = arr;   // copy for descending

    heapSortAscending(arr);
    heapSortDescending(arr2);

    cout << "Ascending: ";
    for(int x : arr)
        cout << x << " ";

    cout << "\nDescending: ";
    for(int x : arr2)
        cout << x << " ";

    return 0;
}