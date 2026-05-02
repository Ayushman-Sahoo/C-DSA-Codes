#include<iostream>
using namespace std;

int diagonalSum(int arr[][4], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += arr[i][j]; // Primary diagonal
            }
            else if (j == n - i - 1) {
                sum += arr[i][j]; // Secondary diagonal
            }
        }
    }
    return sum;
}

int main() {
    int n = 4;
    int arr[4][4];

    cout << "Enter elements of 4x4 matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = diagonalSum(arr, n);
    cout << "Sum of both diagonals: " << result << endl;

    return 0;
}
/*#include <iostream>
using namespace std;

int diagonalSum(int mat[][3], int n) {
    int sum = 0;

    // O(N)
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];  // primary diagonal
        if (i != n - i - 1) {
            sum += mat[i][n - i - 1];  // secondary diagonal
        }
    }

    return sum;
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = diagonalSum(mat, 3);
    cout << "Sum of diagonals: " << result << endl;

    return 0;
}*/