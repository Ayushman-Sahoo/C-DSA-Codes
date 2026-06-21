/*79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word,
         int i, int j, int k) {

    if (k == word.size())
        return true;

    int m = board.size();
    int n = board[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n ||
        board[i][j] != word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found =
        dfs(board, word, i + 1, j, k + 1) ||
        dfs(board, word, i - 1, j, k + 1) ||
        dfs(board, word, i, j + 1, k + 1) ||
        dfs(board, word, i, j - 1, k + 1);

    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }

    return false;
}

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    cout << "Enter grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cout << "Enter word: ";
    cin >> word;

    if (exist(board, word))
        cout << "true";
    else
        cout << "false";

    return 0;
}