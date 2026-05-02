// Rat in a Maze using Backtracking
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Recursive function to find all paths
void solveMazeUtil(int maze[][4], int x, int y, string sol, int N,
                   vector<vector<bool>> vis)
{
    // If destination is reached, print path
    if (x == N-1 && y == N-1 && maze[x][y] == 1)
    {
        cout << sol << "\n";
        return;
    }

    // Move UP
    if (x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1)
    {
        vis[x][y] = true;                  // mark visited
        solveMazeUtil(maze, x-1, y, sol+"U", N, vis);
        vis[x][y] = false;                 // backtrack
    }

    // Move DOWN
    if (x+1 < N && !vis[x+1][y] && maze[x+1][y] == 1)
    {
        vis[x][y] = true;
        solveMazeUtil(maze, x+1, y, sol+"D", N, vis);
        vis[x][y] = false;
    }

    // Move RIGHT
    if (y+1 < N && !vis[x][y+1] && maze[x][y+1] == 1)
    {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y+1, sol+"R", N, vis);
        vis[x][y] = false;
    }

    // Move LEFT
    if (y-1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1)
    {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y-1, sol+"L", N, vis);
        vis[x][y] = false;
    }
}

// Function to initialize visited array
void solveMaze(int maze[][4], int N)
{
    string sol = "";   // stores path

    // visited matrix initialized with false
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    // start if first cell is open
    if (maze[0][0] == 1)
        solveMazeUtil(maze, 0, 0, sol, N, vis);
    else
        cout << "No path exists";
}

int main()
{
    int n;

    // Take size input (max 4)
    cout << "Enter maze size (max 4): ";
    cin >> n;

    int maze[4][4];

    // Take maze input
    cout << "Enter maze (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    // Call function
    cout << "Possible paths are:\n";
    solveMaze(maze, n);

    return 0;
}
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solveMazeUtil(int maze[][4], int x, int y, string sol, int N,
vector<vector<bool>> vis) {
if (x == N-1 && y == N-1 && maze[x][y] == 1) {
cout << sol << "\n";
return;
}
//up
if(x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1) {
vis[x][y] = true;
solveMazeUtil(maze, x-1, y, sol+"U", N, vis);
vis[x][y] = false;
}
//down
if(x+1 < N && !vis[x+1][y] && maze[x+1][y] == 1) {
vis[x][y] = true;
solveMazeUtil(maze, x+1, y, sol+"D", N, vis);
vis[x][y] = false;
}
//right
if(y+1 < N && !vis[x][y+1] && maze[x][y+1] == 1) {
vis[x][y] = true;
solveMazeUtil(maze, x, y+1, sol+"R", N, vis);
vis[x][y] = false;
}
//left
if(y-1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1) {
vis[x][y] = true;
solveMazeUtil(maze, x, y-1, sol+"L", N, vis);
vis[x][y] = false;
}
}
void solveMaze(int maze[][4], int N) {
string sol = "";
vector<vector<bool>> vis(N, vector<bool> (N, false));
if(maze[0][0] == 1) { // only move if the initial position allows
solveMazeUtil(maze, 0, 0, sol, N, vis);
}
}
int main(){
int n = 4;
int maze[4][4] = { { 1, 0, 0, 0 },
{ 1, 1, 0, 1 },
{ 1, 1, 0, 0 },
{ 0, 1, 1, 1 } };
solveMaze(maze, n);
}*/