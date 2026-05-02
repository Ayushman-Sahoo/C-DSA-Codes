#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to store path from root to given node
bool rootToNode(Node* root, int n, vector<int>& path) {
    if (!root)
        return false;

    path.push_back(root->data);

    if (root->data == n)
        return true;

    if (rootToNode(root->left, n, path) || 
        rootToNode(root->right, n, path))
        return true;

    path.pop_back();   // backtracking
    return false;
}

// Function to find LCA (Path Method)
int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    if (!rootToNode(root, n1, path1) || 
        !rootToNode(root, n2, path2)) {
        return -1;   // if any node not found
    }

    int lca = -1;

    for (int i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i])
            break;
        lca = path1[i];
    }

    return lca;
}

// Optimized Recursive LCA
Node* LCA2(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    
    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {

    // Example Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 4;
    int n2 = 5;

    // Using Path Method
    int ans = LCA(root, n1, n2);
    if (ans != -1)
        cout << "LCA (Path Method): " << ans << endl;
    else
        cout << "One or both nodes not found." << endl;

    // Using Optimized Recursive Method
    Node* ans2 = LCA2(root, n1, n2);
    if (ans2 != NULL)
        cout << "LCA (Optimized Recursive): " << ans2->data << endl;
    else
        cout << "One or both nodes not found." << endl;

    return 0;
}