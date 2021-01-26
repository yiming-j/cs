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
private:
    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int left = root->left ? dfs(root->left) : INT_MAX;
        int right = root->right ? dfs(root->right) : INT_MAX;
        return min(left, right) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs(root);
    }
};