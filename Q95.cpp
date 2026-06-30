/*95. Unique Binary Search Trees II
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
Constraints:

1 <= n <= 8
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        for (int i = start; i <= end; i++) {

            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};

void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    Solution obj;
    vector<TreeNode*> ans = obj.generateTrees(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        preorder(ans[i]);
        cout << endl;
    }

    return 0;
}