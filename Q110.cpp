/*110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:
Input: root = []
Output: true
Constraints:
The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Definition for Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = height(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

// Function to build tree using level order input
TreeNode* buildTree() {
    int data;
    cout << "Enter root value (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftData, rightData;

        cout << "Enter left child of " << current->val << " (-1 for NULL): ";
        cin >> leftData;

        if (leftData != -1) {
            current->left = new TreeNode(leftData);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for NULL): ";
        cin >> rightData;

        if (rightData != -1) {
            current->right = new TreeNode(rightData);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    TreeNode* root = buildTree();

    Solution obj;

    if (obj.isBalanced(root))
        cout << "\nThe Binary Tree is Height Balanced." << endl;
    else
        cout << "\nThe Binary Tree is NOT Height Balanced." << endl;

    return 0;
}