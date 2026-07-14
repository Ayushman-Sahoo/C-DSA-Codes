/*130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
Example 2:
Input: board = [["X"]]
Output: [["X"]]
Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, int i, int j) {
    int m = board.size();
    int n = board[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
        return;

    board[i][j] = '#';

    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    // Check first and last column
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O')
            dfs(board, i, 0);

        if (board[i][n - 1] == 'O')
            dfs(board, i, n - 1);
    }

    // Check first and last row
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O')
            dfs(board, 0, j);

        if (board[m - 1][j] == 'O')
            dfs(board, m - 1, j);
    }

    // Flip surrounded O's and restore safe O's
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    cout << "Enter the board (X/O):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    cout << "\nFinal Board:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}