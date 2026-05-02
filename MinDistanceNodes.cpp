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

// Forward declaration of LCA
Node* LCA(Node* root, int n1, int n2);

int findDistance(Node* root, int n, int dist) {
    if (root == NULL) {
        return -1; 
    }

    if (root->data == n) {
        return dist;
    }

    int leftDist = findDistance(root->left, n, dist + 1);
    if (leftDist != -1) {
        return leftDist;
    }

    return findDistance(root->right, n, dist + 1);
}

int minDistance(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);
    if (lca == NULL) {
        return -1; 
    }

    int dist1 = findDistance(lca, n1, 0);
    int dist2 = findDistance(lca, n2, 0);

    return dist1 + dist2;
}

Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 4;
    int n2 = 6;

    cout << "Minimum Distance: "
         << minDistance(root, n1, n2);

    return 0;
}