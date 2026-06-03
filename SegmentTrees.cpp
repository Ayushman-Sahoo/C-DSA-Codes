#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
    vector<int> tree; // Stores the segment tree
    int n;            // Size of the original array

public:

    // Constructor: Initialize tree and build segment tree
    SegmentTree(vector<int>& arr){
        n = arr.size();
        tree.resize(4*n); // Allocate enough space for segment tree
        build(arr, 0, 0, n-1);
    }

    // Range Sum Query Function
    // Returns the sum of elements in range [qi, qj]
    int rangeSum(int si, int sj, int qi, int qj, int node){

        // No overlap
        if(qi > sj || qj < si)
            return 0;

        // Complete overlap
        if(qi <= si && qj >= sj)
            return tree[node];

        // Partial overlap
        int mid = si + (sj - si) / 2;

        int leftSum = rangeSum(si, mid, qi, qj, 2*node + 1);
        int rightSum = rangeSum(mid + 1, sj, qi, qj, 2*node + 2);

        return leftSum + rightSum;
    }

    // Update Function
    // Updates the value at a given index
    void update(int si, int sj, int index, int value, int node){

        // Leaf node reached
        if(si == sj){
            tree[node] = value;
            return;
        }

        int mid = si + (sj - si) / 2;

        // Go to left subtree
        if(index <= mid){
            update(si, mid, index, value, 2*node + 1);
        }

        // Go to right subtree
        else{
            update(mid + 1, sj, index, value, 2*node + 2);
        }

        // Recalculate current node value
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }

    // Build Segment Tree
    void build(vector<int>& arr, int index, int low, int high){

        // Leaf node
        if(low == high){
            tree[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        // Build left subtree
        build(arr, 2*index + 1, low, mid);

        // Build right subtree
        build(arr, 2*index + 2, mid + 1, high);

        // Store sum of left and right child
        tree[index] = tree[2*index + 1] + tree[2*index + 2];
    }

    // Print the segment tree
    void print(){
        for(int i = 0; i < 4*n; i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    // Public function for range query
    int rangeQuery(int qi, int qj){
        return rangeSum(0, n-1, qi, qj, 0);
    }

    // Public function for update query
    void updateQuery(int index, int value){
        update(0, n-1, index, value, 0);
    }
};

int main(){

    // Original array
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    // Create Segment Tree
    SegmentTree st(arr);

    // Range Sum Queries
    cout << st.rangeQuery(0, 3) << endl; // 1+2+3+4 = 10
    cout << st.rangeQuery(2, 5) << endl; // 3+4+5+6 = 18
    cout << st.rangeQuery(6, 7) << endl; // 7+8 = 15

    // Update index 3 with value 10
    st.updateQuery(3, 10);

    cout << st.rangeQuery(0, 3) << endl; // 1+2+3+10 = 16

    return 0;
}