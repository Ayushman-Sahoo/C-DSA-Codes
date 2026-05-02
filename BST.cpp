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

// insert in BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// search in BST
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// build BST from array
Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// delete in BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // case 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // case 2: one child
        else if (root->left == NULL || root->right == NULL) {
            Node* child = (root->left != NULL) ? root->left : root->right;
            delete root;
            return child;
        }

        // case 3: two children
        else {
            Node* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

// print nodes in range
void printInRange(Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        printInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        cout << root->data << " ";

    if (root->data < high)
        printInRange(root->right, low, high);
}

// print single path
void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
}

// store ALL root-to-leaf paths
void Helper(Node* root, vector<int>& path, vector<vector<int>>& allPaths) {
    if (root == NULL)
        return;

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        allPaths.push_back(path);
    }
    else {
        Helper(root->left, path, allPaths);
        Helper(root->right, path, allPaths);
    }

    path.pop_back();
}

// return all root-to-leaf paths
vector<vector<int>> rootToLeaf(Node* root) {
    vector<int> path;
    vector<vector<int>> allPaths;
    Helper(root, path, allPaths);
    return allPaths;
}

// validate BST
bool validateHelper(Node* root, long minVal, long maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return validateHelper(root->left, minVal, root->data) &&
           validateHelper(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return validateHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    int arr[7] = {5, 3, 7, 2, 4, 6, 8};
    Node* root = buildBST(arr, 7);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Search 4: " << (search(root, 4) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (search(root, 10) ? "Found" : "Not Found") << endl;

    root = deleteNode(root, 3);

    cout << "After Deletion (3): ";
    inorder(root);
    cout << endl;

    cout << "Nodes in range [4, 7]: ";
    printInRange(root, 4, 7);
    cout << endl;

    cout << "Is BST: " << (isBST(root) ? "Yes" : "No") << endl;

    cout << "Root to Leaf Paths:\n";
    vector<vector<int>> paths = rootToLeaf(root);
    for (auto p : paths)
        printPath(p);

    return 0;
}