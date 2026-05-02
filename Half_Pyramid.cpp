#include <iostream>
using namespace std;

int main() {
  int n;
  cout<<"Enter the rows to print:";
  cin>>n;
  for (int row = 1; row <= n; row++) {
    for (int num = 1; num <= row; num++) {
      cout << num;
      }
      cout << endl;
    }
    return 0;
}
