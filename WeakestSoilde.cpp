/*K Weakest Soldiers in a Matrix
You are given an M × N matrix where:
1 represents a soldier
0 represents a civilian
In each row, soldiers (1s) always appear before civilians (0s). A row i is weaker than row j if:
The number of soldiers in row i is less than the number of soldiers in row j, or Both rows have the same number of soldiers, but i < j. Your task is to find the indices of the K weakest rows in the matrix.
Example: 
Matrix: 
1 0 0 0
1 1 1 1
1 0 0 0
1 0 0 0*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Row {
public:
    int idx;
    int soldiers;
    Row(int idx, int soldiers) {
        this->idx = idx;
        this->soldiers = soldiers;  
    }
    bool operator <(const Row& other) const {
        if(this->soldiers == other.soldiers) return this->idx < other.idx; 
        return this->soldiers < other.soldiers; 
    }
};

void weakestRows(vector<vector<int>> matrix, int K) {
    vector<Row> rows;

    for(int i=0; i<matrix.size(); i++) { // O(m*n)
        int count = 0;
        for(int j=0; j<matrix[i].size(); j++) {
            if(matrix[i][j] == 1) count++;
            else break;
        }
        rows.push_back(Row(i, count));
    }

    priority_queue<Row> pq(rows.begin(), rows.end()); // O(m)

    for(int i=0; i<K; i++) { // O(K)
        cout << "Row " << pq.top().idx << " has " << pq.top().soldiers << " soldiers." << endl;
        pq.pop();
    }
}

int main() {
  vector<vector<int>> matrix = {
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
  };
  int K = 2;
  weakestRows(matrix, K);
  return 0;
}