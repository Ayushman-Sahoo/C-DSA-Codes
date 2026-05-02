#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
  vector<int> temp;

  int i=si; //left part starting index
  int j=mid+1; //right part starting index

  // Compare elements from both halves
  while (i <= mid && j <= ei)
  {
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i++]);
    }
    else
    {
      temp.push_back(arr[j++]);
    }
  }

   // Copy remaining elements from left half
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from right half
    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    // Copy temp array back to original array
    for (int idx = si, x = 0; idx <= ei; idx++, x++)
    {
        arr[idx] = temp[x];
    }

    }

// Merge Sort function
void mergeSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);        // left half
    mergeSort(arr, mid + 1, ei);    // right half

    merge(arr, si, mid, ei);
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter "<<n<<" elements in array: ";
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  mergeSort(arr, 0, n-1);

  cout<<"Sorted array: ";
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  return 0; 
}