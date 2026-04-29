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
    int goodNodes(TreeNode* root) {
        int answer = 0;
        queue<pair<TreeNode*, int>> q; // node to process, max value encountered so far
        q.push({root, root->val});
        while (!q.empty()) {
            auto [node, mx] = q.front();
            q.pop();

            if (node->val >= mx) ++answer;
            if (node->left) {
                q.push({node->left, max(mx, node->val)});
            } 
            if (node->right) {
                q.push({node->right, max(mx, node->val)});
            }
        }

        return answer;
    }
};
