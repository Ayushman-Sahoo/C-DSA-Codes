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
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Global index for building tree
int index1 = -1;

// Build tree from preorder vector
Node* buildTree(vector<int>& nodes) {
    index1++;

    if (nodes[index1] == -1) {
        return nullptr;
    }

    Node* newNode = new Node(nodes[index1]);
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subroot) {
    if (root == nullptr && subroot == nullptr) {
        return true;
    }
    if (root == nullptr || subroot == nullptr) {
        return false;
    }

    if (root->data == subroot->data) {
        if (isIdentical(root, subroot)) {
            return true;
        }
    }

    bool isLeftSubtree = isSubtree(root->left, subroot);
    if (!isLeftSubtree) {
        return isSubtree(root->right, subroot);
    }

    return true;
}

int main() {

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);   

    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);

    cout << "Is subroot a subtree of root? "
         << (isSubtree(root, subroot) ? "Yes" : "No") << endl;

    return 0;
}