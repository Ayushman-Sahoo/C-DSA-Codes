/* 51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 
Constraints:

1 <= n <= 9
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check upper column
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
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';   // Place Queen

                solve(board, row + 1, n);

                board[row][col] = '.';   // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return result;
    }
};

int main() {
    int n;

    cout << "Enter value of n: ";
    cin >> n;

    Solution obj;

    vector<vector<string>> answers = obj.solveNQueens(n);

    cout << "\nTotal Solutions = " << answers.size() << endl;

    for (int i = 0; i < answers.size(); i++) {

        cout << "\nSolution " << i + 1 << ":" << endl;

        for (string row : answers[i]) {
            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}