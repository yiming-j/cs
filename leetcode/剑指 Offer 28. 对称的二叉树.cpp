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
    bool dfs(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }
        if (l == nullptr || r == nullptr) {
            return false;
        }
        return l->val == r->val && dfs(l->right, r->left) && dfs(l->left, r->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return dfs(root->left, root->right);
    }
};