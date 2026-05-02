//Recursive Function to find occurrences of an element in an array
#include <iostream>
using namespace std;

void findOccurances(int arr[],  int key, int i, int n){
  if(i==n){
    return;
  }
  if(arr[i]==key){
    cout<<i<<" ";
  }
  findOccurances(arr, key, i+1, n);
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
  int key;
  cout<<"Enter element to find occurrences of: ";
  cin>>key;
  cout<<"Occurrences at indices: ";
  findOccurances(arr, key, 0, n);
}

// Loop to find occurrences of an element in an array
/*#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n = 9;
    int key = 2;

    cout << "Indices where key is found: ";

    // Loop to check each element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << i << " ";
        }
    }

    return 0;
}*/