/*59. Spiral Matrix II 
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 20
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int num = 1;

    while (top <= bottom && left <= right) {

        // Fill top row (left -> right)
        for (int col = left; col <= right; col++) {
            matrix[top][col] = num++;
        }
        top++;

        // Fill right column (top -> bottom)
        for (int row = top; row <= bottom; row++) {
            matrix[row][right] = num++;
        }
        right--;

        // Fill bottom row (right -> left)
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                matrix[bottom][col] = num++;
            }
            bottom--;
        }

        // Fill left column (bottom -> top)
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                matrix[row][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> result = generateMatrix(n);

    cout << "\nSpiral Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}