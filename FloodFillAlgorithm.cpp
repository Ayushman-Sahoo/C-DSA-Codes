#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, int n, int m,
             vector<vector<int>>& image,
             vector<vector<bool>>& vis,
             int newColor, int oldColor) {

        vis[row][col] = true;
        image[row][col] = newColor;

        // up
        if (row - 1 >= 0 && !vis[row - 1][col] && image[row - 1][col] == oldColor) {
            dfs(row - 1, col, n, m, image, vis, newColor, oldColor);
        }

        // down
        if (row + 1 < n && !vis[row + 1][col] && image[row + 1][col] == oldColor) {
            dfs(row + 1, col, n, m, image, vis, newColor, oldColor);
        }

        // left
        if (col - 1 >= 0 && !vis[row][col - 1] && image[row][col - 1] == oldColor) {
            dfs(row, col - 1, n, m, image, vis, newColor, oldColor);
        }

        // right
        if (col + 1 < m && !vis[row][col + 1] && image[row][col + 1] == oldColor) {
            dfs(row, col + 1, n, m, image, vis, newColor, oldColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        if (oldColor == newColor) return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(sr, sc, n, m, image, vis, newColor, oldColor);

        return image;
    }
};

int main() {
    Solution obj;

    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    cout << "Enter the matrix values:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cout << "Enter starting row, starting column and new color: ";
    cin >> sr >> sc >> newColor;

    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "Result after flood fill:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}