/*#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    return 0;
}*/

#include <iostream>
using namespace std;

// Updated to accept variable column size using template parameter
void spiralMatrix(int matrix[][100], int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while (srow <= erow && scol <= ecol)
    {
      //top
      for(int j = scol; j <= ecol; j++){
        cout << matrix[srow][j] << " ";
      }
      //right
      for(int i = srow+1; i <= erow; i++){
        cout << matrix[i][ecol] << " ";
      }
      //bottom
      if (srow < erow) {
        for(int j = ecol-1; j >= scol; j--){
          if(srow == erow) { //middle
              break;
          }
          cout << matrix[erow][j] << " ";
        }
      }
      //left
      if (scol < ecol) {
        for(int i = erow-1; i >= srow+1; i--){
          if(scol == ecol) { //middle
              break;
          }
          cout << matrix[i][scol] << " ";
        }
      }
      srow++;
      erow--;
      scol++;
      ecol--;
    }
}

int main(){
    /*int matrix[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
    };

    spiralMatrix(matrix, 3, 4);*/

    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    int matrix[100][100]; // assuming max size 100x100

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Spiral order:\n";
    spiralMatrix(matrix, n, m);
    return 0;
}