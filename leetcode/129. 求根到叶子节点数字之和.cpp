/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, int sum) {
        if (node->left == nullptr && node->right == nullptr) {
            ans += sum;
            return;
        } 
        if (node->left) {
            dfs(node->left, sum * 10 + node->left->val);
        }
        if (node->right) {
            dfs(node->right, sum * 10 + node->right->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, root->val);
        return ans;
    }
};