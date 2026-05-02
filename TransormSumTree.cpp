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

// Transform to Sum Tree (Old value method)
int transformToSumTree(Node* root) {
    if (root == NULL)
        return 0;

    // store old value
    int oldValue = root->data;

    // get old subtree sums
    int leftOld = transformToSumTree(root->left);
    int rightOld = transformToSumTree(root->right);

    // update node with sum of old left and right
    root->data = leftOld + rightOld;

    // return total old sum of this subtree
    return oldValue + root->data;
}

// inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    transformToSumTree(root);

    cout << "Inorder of Sum Tree: ";
    inorder(root);

    return 0;
}