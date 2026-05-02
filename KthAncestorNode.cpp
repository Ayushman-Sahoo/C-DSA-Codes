#include <iostream>
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

int KthAncestorNode(Node *root, int node, int k) {
    if (root == NULL)
        return -1;

    if (root->data == node)
        return 0;

    int left = KthAncestorNode(root->left, node, k);
    int right = KthAncestorNode(root->right, node, k);

    if (left != -1) {
        if (left + 1 == k) {
            cout << "Kth Ancestor: " << root->data << endl;
        }
        return left + 1;
    }

    if (right != -1) {
        if (right + 1 == k) {
            cout << "Kth Ancestor: " << root->data << endl;
        }
        return right + 1;
    }

    return -1;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int node = 5;
    int k = 2;

    KthAncestorNode(root, node, k);

    return 0;
}