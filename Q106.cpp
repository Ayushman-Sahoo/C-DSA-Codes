/*106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {

        if (left > right)
            return NULL;

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int index = mp[rootValue];

        root->right = build(postorder, index + 1, right);
        root->left = build(postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};

void preorderPrint(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    Solution obj;

    TreeNode* root = obj.buildTree(inorder, postorder);

    cout << "Preorder of Constructed Tree: ";
    preorderPrint(root);

    return 0;
}