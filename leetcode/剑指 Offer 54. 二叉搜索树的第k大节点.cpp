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
    int ret = 0, k = 0;
    void dfs(TreeNode* node) {
        if (k == 0) {
            return;
        }
        if (node == nullptr) {
            return;
        }
        dfs(node->right);
        if (--k == 0) {
            ret = node->val;
            return;
        }
        dfs(node->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ret;
    }
};