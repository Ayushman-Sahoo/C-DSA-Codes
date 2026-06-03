/* 52. N-Queens II
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 
Constraints:

1 <= n <= 9
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int count = 0;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i++, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        // Found one valid arrangement
        if (row == n) {
            count++;
            return;
        }

        // Try every column in the current row
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Place Queen
                board[row][col] = 'Q';

                // Recur for next row
                solve(board, row + 1, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return count;
    }
};

int main() {
    int n;

    cout << "Enter value of n: ";
    cin >> n;

    Solution obj;

    int answer = obj.totalNQueens(n);

    cout << "\nTotal Number of Solutions = " << answer << endl;

    return 0;
}