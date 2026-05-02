#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int index1 = -1;   // Added (needed for buildTree)

Node* buildTree(vector<int>& nodes) {   // Added
    index1++;

    if (nodes[index1] == -1) {
        return NULL;
    }

    Node* newNode = new Node(nodes[index1]);
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}

int height(Node* root) {   // O(n)
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int diam1(Node* root) {   // O(n^2)
    if (root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;   // O(n)
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

// Optimized approach to find diameter of a tree in O(n) time
pair<int, int> diam2(Node* root) {   // O(n)
    if (root == NULL) {
        return {0, 0};   // {diameter, height}
    }

    pair<int, int> left = diam2(root->left);
    pair<int, int> right = diam2(root->right);

    int currDiam = left.second + right.second + 1;
    int maxDiam = max(currDiam, max(left.first, right.first));
    int currHeight = max(left.second, right.second) + 1;

    return {maxDiam, currHeight};
}

int main() {

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    Node* root = buildTree(nodes);

    cout << "Diameter of the tree: " << diam1(root) << endl;
    cout << "Diameter of the tree (optimized): " << diam2(root).first << endl;
    return 0;
}