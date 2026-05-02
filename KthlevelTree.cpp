//Iterative approach
/*#include <iostream>
#include <queue>
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

// Function to print Kth level iteratively
void printKthLevel(Node* root, int k) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;

    while (!q.empty()) {

        int size = q.size();   // number of nodes at current level

        if (level == k) {
            // Print all nodes at Kth level
             for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
            }
            return;  // stop after printing kth level
        }

        // Otherwise push next level nodes
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
          }

        level++;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k = 2;
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);

    return 0;
}*/

// Recursive approach
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

void kthHelper(Node* root, int k, int currentLevel) {
    if (root == NULL) {
        return;
    }

    if (currentLevel == k) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currentLevel + 1);
    kthHelper(root->right, k, currentLevel + 1);
}

void printKthLevel(Node* root, int k) {
    kthHelper(root, k, 1);
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k = 2;
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);

    return 0;
}