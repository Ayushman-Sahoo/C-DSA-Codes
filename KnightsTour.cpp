//Knight’s Tour 
#include <iostream>
using namespace std;

// Function to check if move is valid
bool isSafe(int x, int y, int sol[][8], int N)
{
    // Check board limits and unvisited cell
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Function to print solution matrix
void printSolution(int sol[][8], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Recursive function using backtracking
bool solveKTUtil(int x, int y, int movei, int sol[][8],
                 int xMove[], int yMove[], int N)
{
    // If all cells are visited
    if (movei == N * N)
        return true;

    // Try all 8 possible moves
    for (int k = 0; k < 8; k++)
    {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if (isSafe(next_x, next_y, sol, N))
        {
            sol[next_x][next_y] = movei; // mark move

            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove, N))
                return true;
            else
                sol[next_x][next_y] = -1; // backtracking
        }
    }
    return false;
}

// Main function to solve Knight Tour
bool solveKT(int N)
{
    int sol[8][8];

    // Initialize board with -1
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = -1;

    // All possible knight moves
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0; // starting position

    // Call recursive function
    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove, N))
    {
        cout << "Solution does not exist\n";
        return false;
    }
    else
        printSolution(sol, N);

    return true;
}

int main()
{
    int N;

    // Take user input
    cout << "Enter board size (max 8): ";
    cin >> N;

    // Solve Knight Tour
    solveKT(N);

    return 0;
}