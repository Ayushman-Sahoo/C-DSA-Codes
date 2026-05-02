#include <iostream>
#include <vector>
#include <queue>
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

static int index = -1;
Node* buildTree(vector<int> nodes, int& index) {
    index++;
    if(index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }

    Node* newNode = new Node(nodes[index]);
    newNode->left = buildTree(nodes, index); // recursive call to build left subtree
    newNode->right = buildTree(nodes, index); // recursive call to build right subtree

    return newNode;
}


// Preorder traversal: root -> left -> right
void preorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " "; // Process the current node
    preorder(root->left); // Traverse the left subtree
    preorder(root->right); // Traverse the right subtree
}

// Inorder traversal: left -> root -> right
void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left); // Traverse the left subtree
    cout << root->data << " "; // Process the current node
    inorder(root->right); // Traverse the right subtree
}

// Postorder traversal: left -> right -> root
void postorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    postorder(root->left); // Traverse the left subtree
    postorder(root->right); // Traverse the right subtree
    cout << root->data << " "; // Process the current node
}

//Level order traversal: level by level from left to right
void levelOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current == NULL)
        {
          if (q.empty())
          {
            return; // No more nodes to process
          }
          cout << endl; // Move to the next line for the next level
          q.push(NULL); // Add a marker for the end of the current level
        }
        else
        {
          cout << current->data << " "; // Process the current node

          if (current->left != NULL)
          {
            q.push(current->left); // Enqueue left child
          }
          if (current->right != NULL)
          {
            q.push(current->right); // Enqueue right child
          }
        }
    }
}

/*
//level order traversal: level by level from left to right
// print in 1 line 
void levelOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " "; // Process the current node

        if(current->left != nullptr) {
            q.push(current->left); // Enqueue left child
        }
        if(current->right != nullptr) {
            q.push(current->right); // Enqueue right child
        }
    }
}
*/

//Height of a binary tree
int height(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1; // Add 1 for the current node
}

//count number of nodes in a binary tree
int countNodes(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1; // Add 1 for the current node
}

//sum of all nodes in a binary tree
int sumNodes(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    cout << "leftSum = " << leftSum << ", rightSum = " << rightSum << ", root->data = " << root->data << endl;
    return leftSum + rightSum + root->data; // Add the value of the current node
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes, index);
    buildTree(nodes, index);
    cout << root->data << endl; // Output: 1
    preorder(root); // Output: 1 2 4 5 3 6
    cout << endl;
    inorder(root); // Output: 4 2 5 1 3 6
    cout << endl;
    postorder(root); // Output: 4 5 2 6 3 1
    cout << endl;
    levelOrder(root); // Output: 1 2 3 4 5 6
    cout << endl;
    cout << "Height of the tree: " << height(root) << endl; 
    cout << "Number of nodes in the tree: " << countNodes(root) << endl;
    cout << "Sum of all nodes in the tree: " << sumNodes(root) << endl;
    return 0;
}