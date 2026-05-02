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

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Store inorder traversal in vector
void inorder(Node* root, vector<int>& nodes) {
    if (root == NULL)
        return;

    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

// Build balanced BST from sorted array
Node* buildBSTFromSortedArray(vector<int>& nodes, int start, int end) {
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(nodes[mid]);

    root->left = buildBSTFromSortedArray(nodes, start, mid - 1);
    root->right = buildBSTFromSortedArray(nodes, mid + 1, end);

    return root;
}

// Convert unbalanced BST to balanced BST
Node* balancedBST(Node* root) {
    if (root == NULL)
        return NULL;

    vector<int> nodes;
    inorder(root, nodes);

    return buildBSTFromSortedArray(nodes, 0, nodes.size() - 1);
}

int main() {
    // Creating unbalanced BST
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    // Balance the BST
    root = balancedBST(root);

    // Inorder Traversal
    cout << "Inorder Traversal of Balanced BST: ";
    vector<int> nodes;
    inorder(root, nodes);
    for (int val : nodes) {
        cout << val << " ";
    }
    cout << endl;

    // Preorder Traversal
    cout << "Preorder Traversal of Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}