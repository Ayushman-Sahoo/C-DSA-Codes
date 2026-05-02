#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildBSTFromSortedArray(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSortedArray(arr, start, mid - 1);
    root->right = buildBSTFromSortedArray(arr, mid + 1, end);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    Node* root = buildBSTFromSortedArray(arr, 0, 6);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}