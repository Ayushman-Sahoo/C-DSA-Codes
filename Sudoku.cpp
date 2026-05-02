// Sudoku Solver using Backtracking
#include <iostream>
using namespace std;

// Function to print Sudoku board
void printSudoku(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if placing digit is safe
bool isSafe(int sudoku[9][9], int row, int col, int digit)
{
    // Check row
    for (int j = 0; j < 9; j++)
        if (sudoku[row][j] == digit)
            return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (sudoku[i][col] == digit)
            return false;

    // Check 3×3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (sudoku[i][j] == digit)
                return false;

    return true; // safe to place digit
}

bool sudokuSolver(int sudoku[9][9], int row, int col)
{
    // BASE CASE: if reached beyond last row → solution found
    if (row == 9)
    {
        printf("Solution found:\n");
        printSudoku(sudoku);
        return true;
    }

    // Calculate next cell position
    int nextRow = row;
    int nextCol = col + 1;

    // Move to next row if column ends
    if (col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If cell already filled → move to next cell
    if (sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // Try digits 1 to 9
    for (int digit = 1; digit <= 9; digit++) {

        // Check if safe to place digit
        if (isSafe(sudoku, row, col, digit)) {

            sudoku[row][col] = digit; // place digit

            // Recursive call to next cell
            if (sudokuSolver(sudoku, nextRow, nextCol))
                return true;

            sudoku[row][col] = 0; // BACKTRACK (remove digit)
        }
    }

    return false; // no solution found
}

int main()
{
    // Sudoku board (0 means empty cell)
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0 ,5},
        {0 ,0 ,0 ,0 ,8 ,0 ,0 ,7 ,9}
    };

    // Start solving from first cell
    sudokuSolver(board, 0, 0);

    return 0;
}