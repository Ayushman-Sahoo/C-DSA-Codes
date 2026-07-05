/*105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {

        if (left > right)
            return NULL;

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int index = mp[rootValue];

        root->left = build(preorder, left, index - 1);
        root->right = build(preorder, index + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};

void printLevel(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";

    printLevel(root->left);
    printLevel(root->right);
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Preorder of Constructed Tree: ";
    printLevel(root);

    return 0;
}