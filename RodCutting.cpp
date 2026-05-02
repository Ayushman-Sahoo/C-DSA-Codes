/*Given a rod of length 8, cut the rod into smaller pieces such that the maximum profit is obtained by selling the pieces.
You are given:
length[] = {1, 2, 3, 4, 5, 6, 7, 8}
price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Each length[i] has corresponding selling price price[i].
You can cut the rod into any number of pieces, and pieces of the same length can be used multiple times.
Return the maximum profit possible.
Example:

Input:
rodLength = 8
length[] = {1,2,3,4,5,6,7,8}
price[] = {1,5,8,9,10,17,17,20}

Output:
22
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int> price, vector<int> length, int rodLength) {
    int n = length.size();

    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < rodLength+1; j++) {
            if(length[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j - length[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;

    cout << rodCutting(price, length, rodLength);

    return 0;
}