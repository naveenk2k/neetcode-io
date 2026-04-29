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

class Solution {
public:
    void inOrder(TreeNode *node, vector<int>& values) {
        if (!node) return;
        inOrder(node->left, values);
        values.push_back(node->val);
        inOrder(node->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        inOrder(root, values);
        return values[k-1];
    }
};
