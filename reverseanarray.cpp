/*#include<iostream>
using namespace std;
int main(){
  int n;
  cout<< "Enter the number of elements: ";
  cin>> n;
  int arr[n], rev[n];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }
  // Copy elements in reverse order to another array
  for (int i = 0; i < n; i++) {
    rev[i] = arr[n - i - 1];
  }
   cout << "Reversed array (using extra space): ";
    for (int i = 0; i < n; i++) {
        cout << rev[i] << " ";
    }
    cout << endl;
    return 0;
}*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Swap elements from start and end
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    cout << "Reversed array (without extra space): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}