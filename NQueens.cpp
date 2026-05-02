// N Queens Problem using Backtracking have a mixed solution count of all solution and print any one solution 
#include <iostream>
#include <vector>
using namespace std;

// Function to print the chess board
void printBoard(vector<vector<char>> &board)
{
    int n = board.size();

    cout << "One possible solution:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing Queen at (row, col) is safe
bool isSafe(vector<vector<char>> &board, int row, int col)
{
    int n = board.size();

    // Check vertical column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Backtracking function to place Queens
int nQueens(vector<vector<char>> &board, int row)
{
    int n = board.size();
    int count = 0;

    // Base case: all queens placed
    if (row == n)
    {
        printBoard(board);
        return 1;   // found a solution
    }

    // Try placing queen in each column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';     // Place Queen

           // count += nQueens(board, row + 1);   // Recursive call
          // if solution found, stop further recursion
            if (nQueens(board, row + 1))
                return true;
            board[row][col] = '.';     // Backtrack
        }
    }
    //return count; // no of possible solutions found in this path
    return 0;   // no solution found in this path
}

int main()
{
    int n;

    // Ask user for input
    cout << "Enter the number of Queens (N): ";
    cout << "\nThis will create an N x N chess board.\n";
    cout << "Example: Enter 4 for 4x4 board.\n\n";

    cin >> n;

    // Create board with '.'
    vector<vector<char>> board;

    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    // Call N-Queens function
    /*int count = nQueens(board, 0);
    cout << "Total solutions found: " << count << endl;*/
    bool found = nQueens(board, 0);

    if (!found)
    cout << "No solution exists\n";
    return 0;
}