#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int>& nums, int start, int end, int node) {

        if(start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        buildTree(nums, start, mid, 2 * node + 1);
        buildTree(nums, mid + 1, end, 2 * node + 2);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int maxQuery(int qi, int qj, int si, int sj, int node) { // O(log n)

        // No overlap
        if(qi > sj || qj < si) {
            return INT_MIN;
        }

        // Complete overlap
        if(si >= qi && sj <= qj) {
            return tree[node];
        }

        // Partial overlap
        int mid = si + (sj - si) / 2;

        int leftMax = maxQuery(qi, qj, si, mid, 2 * node + 1);
        int rightMax = maxQuery(qi, qj, mid + 1, sj, 2 * node + 2);

        return max(leftMax, rightMax);
    }

    void updateUtil(int index, int value, int si, int sj, int node) {
        if(si == sj) {
            tree[node] = value;
            return;
        }

        int mid = si + (sj - si) / 2;

        if(index <= mid) {
            updateUtil(index, value, si, mid, 2 * node + 1);
        } else {
            updateUtil(index, value, mid + 1, sj, 2 * node + 2);
        }

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        buildTree(nums, 0, n - 1, 0);
    }

    void printTree() {
        for(int i = 0; i < 4 * n; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return maxQuery(qi, qj, 0, n - 1, 0);
    }

    void update(int index, int value) { // O(log n)
        updateUtil(index, value, 0, n - 1, 0);
    }
};

int main() {

    vector<int> nums = {6, 8, -1, 2, 17, 1, 3, 2, 4};

    SegmentTree st(nums);

    st.printTree();

    cout << "Maximum in range [0, 4] = "
         << st.rangeQuery(0, 4) << endl;

    cout << "Maximum in range [2, 8] = "
         << st.rangeQuery(2, 8) << endl;

    return 0;
}