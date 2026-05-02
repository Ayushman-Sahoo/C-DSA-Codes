#include <iostream>
#include <queue>
#include <map>

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

void topView(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<pair<Node*, int>> q;
    map<int, int> topViewMap;

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();

        Node* currentNode = front.first;
        int hd = front.second;

        if (topViewMap.count(hd) == 0)   
        {
            topViewMap[hd] = currentNode->data;  
        }

        if (currentNode->left != nullptr)
        {
            q.push({currentNode->left, hd - 1});
        }
        if (currentNode->right != nullptr)
        {
            q.push({currentNode->right, hd + 1});
        }
    }

    for (auto it : topViewMap)   
    {
        cout << it.second << " ";
    }
}

void bottomView(Node* root) {
    if (root == nullptr) return;

    queue<pair<Node*, int>> q;
    map<int, int> bottomMap;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* current = front.first;
        int hd = front.second;

        // Always overwrite (this makes it bottom view)
        bottomMap[hd] = current->data;

        if (current->left != nullptr)
            q.push({current->left, hd - 1});
              if (current->right != nullptr)
            q.push({current->right, hd + 1});
    }

    for (auto it : bottomMap) {
        cout << it.second << " ";
    }
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);
    topView(root);

    Node* root2 = buildTree(nodes);

    bottomView(root2);
    return 0;
}