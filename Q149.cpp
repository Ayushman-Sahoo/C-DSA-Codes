/*149. Max Points on a Line
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Constraints:
1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.
*/

#include <iostream>
#include <vector>
#include <map>
#include <numeric> // for gcd
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> mp;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize the slope
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }

                mp[{dx, dy}]++;
            }

            int maxi = 0;
            for (auto it : mp)
                maxi = max(maxi, it.second);

            ans = max(ans, maxi + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<vector<int>> points1 = {{1,1}, {2,2}, {3,3}};
    cout << "Maximum points on the same line: "
         << obj.maxPoints(points1) << endl;

    // Example 2
    vector<vector<int>> points2 = {
        {1,1}, {3,2}, {5,3},
        {4,1}, {2,3}, {1,4}
    };
    cout << "Maximum points on the same line: "
         << obj.maxPoints(points2) << endl;

    return 0;
}