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
    bool isValid(TreeNode* node, int min, int max) {
        if (!node) return true;
        if (node->val > min && node->val < max) {
            return isValid(node->left, min, node->val) && isValid(node->right, node->val, max);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, -INT_MAX, INT_MAX);
    }
};
