#include<iostream>
#include<vector>
#include<climits>

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

class Info {
public:
    int size;       
    int minVal;     
    int maxVal;     
    bool isBST;    

    Info(int s, int minV, int maxV, bool b) {
        size = s;
        minVal = minV;
        maxVal = maxV;
        isBST = b;
    }
};

int maxSize = 0;

Info* LargestBST(Node* root) {
    if (root == NULL)
        return new Info(0, INT_MAX, INT_MIN, true);

    Info* leftInfo = LargestBST(root->left);
    Info* rightInfo = LargestBST(root->right);

    int size = leftInfo->size + rightInfo->size + 1;

    int minVal = min(root->data, min(leftInfo->minVal, rightInfo->minVal));
    int maxVal = max(root->data, max(leftInfo->maxVal, rightInfo->maxVal));

    bool isBST = leftInfo->isBST && rightInfo->isBST &&
                 (root->data > leftInfo->maxVal) &&
                 (root->data < rightInfo->minVal);

    if (isBST) {
        maxSize = max(maxSize, size);
    }

    return new Info(size, minVal, maxVal, isBST);
}

int main(){
    Node* root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    LargestBST(root);

    cout << "Size of the largest BST is: " << maxSize << endl;

    return 0;
}