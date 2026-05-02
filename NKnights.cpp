// NKnights - Backtracking problem to place N knights on an N x N chessboard such that no two knights threaten each other.
#include <iostream>
#include <vector>
using namespace std;

// Function to print the chess board
void printBoard(vector<vector<char>> &board)
{
    int n = board.size();   // get board size

    cout << "One possible solution:\n";

    // loop through rows
    for (int i = 0; i < n; i++)
    {
        // loop through columns
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";   // print each cell

        cout << endl;
    }
    cout << endl;
}

// Function to check if placing knight at (row, col) is safe
bool isSafe(vector<vector<char>> &board, int row, int col)
{
    int n = board.size();   // board size

    // All 8 possible knight moves
    int rowMoves[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colMoves[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // Check all 8 directions
    for (int i = 0; i < 8; i++)
    {
        int newRow = row + rowMoves[i];   // calculate new row
        int newCol = col + colMoves[i];   // calculate new column

        // check if inside board
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
        {
            // if knight already present → unsafe
            if (board[newRow][newCol] == 'K')
                return false;
        }
    }

    return true;   // safe to place knight
}

// Backtracking function to place knights
void nKnights(vector<vector<char>> &board, int n, int row, int col, int knightsPlaced)
{
    // BASE CASE: if all knights placed
    if (knightsPlaced == n)
    {
        printBoard(board);   // print solution
        return;
    }

    // if reached end of board
    if (row == n)
        return;

    // if column ends → move to next row
    if (col == n)
    {
        nKnights(board, n, row + 1, 0, knightsPlaced);
        return;
    }

    // Check if safe to place knight
    if (isSafe(board, row, col))
    {
        board[row][col] = 'K';   // place knight

        // recursive call to place next knight
        nKnights(board, n, row, col + 1, knightsPlaced + 1);

        board[row][col] = '.';   // BACKTRACK (remove knight)
    }

    // Try next column without placing knight
    nKnights(board, n, row, col + 1, knightsPlaced);
}

int main()
{
    int n;

    // Take input from user
    cout << "Enter value of N: ";
    cin >> n;

    // Create NxN board and fill with '.'
    vector<vector<char>> board(n, vector<char>(n, '.'));

    // Start placing knights from position (0,0)
    nKnights(board, n, 0, 0, 0);

    return 0;
}
