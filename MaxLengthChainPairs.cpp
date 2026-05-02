/*A pair (c, d) can come after pair (a, b) if b < c.
Find the longest chain which can be formed from a given set of pairs.

Pairs =
(5, 24)
(39, 60)
(5, 28)
(27, 40)
(50, 90)*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int maxChainLength(vector<pair<int, int>> pairs) {
    int n = pairs.size();

    sort(pairs.begin(), pairs.end(), compare);

    int count = 1;
    int lastEnd = pairs[0].second;

    for(int i = 1; i < n; i++) {
        if(pairs[i].first > lastEnd) {
            count++;
            lastEnd = pairs[i].second;
        }
    }

    return count;
}

int main(){
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0, 0));

    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    cout << maxChainLength(pairs);

    return 0;
}