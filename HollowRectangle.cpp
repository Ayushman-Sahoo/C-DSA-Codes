#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "*"; // First column

        for (int j = 1; j <= n - 1; j++) {
            if (i == 1 || i == n) {
                cout << "*"; // Top or bottom row
            } else {
                cout << " "; // Middle rows
            }
        }

        cout << "*" << endl; // Last column
    }

    return 0;
}

/*#include <iostream>
using namespace std;

int main() {
  int rows, cols;
  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= cols; j++) {
      if (i == 1 || i == rows || j == 1 || j == cols) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}*/