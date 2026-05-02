// GridWays - Count the number of ways to reach from top-left to bottom-right of a grid using recursion and backtracking
#include <iostream>
using namespace std;

// Function to print all paths
int gridWays(int r, int c, int m, int n, string path)
{
    // Base case: reached destination
    if (r == m - 1 && c == n - 1)
    {
        cout << path << endl;   // print the path
        return 1;
    }

    // Out of bounds
    if (r >= m || c >= n)
        return 0;

    // Move Right
    int rightWays = gridWays(r, c + 1, m, n, path + "R");

    // Move Down
    int downWays = gridWays(r + 1, c, m, n, path + "D");

    return rightWays + downWays;
}

int main()
{
    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    cout << "\nPossible paths are:\n";

    int ways = gridWays(0, 0, n, m, "");

    cout << "\nTotal number of ways: " << ways;

    return 0;
}