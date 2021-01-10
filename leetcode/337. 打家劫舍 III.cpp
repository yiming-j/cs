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
private:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
    }
public:
    int rob(TreeNode* root) {
        auto ret = dfs(root);
        return max(ret.first, ret.second);
    }
};