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
    int ret;
    
    void dfs(TreeNode* node, double target) {
        if (node == nullptr) {
            return;
        }
        ret = abs(node->val - target) < abs(ret - target) ? node->val : ret;
        if (target < node->val) {
            dfs(node->left, target);
        } else {
            dfs(node->right, target);
        }
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        if (root == nullptr) {
            return 0;
        }
        ret = root->val;
        dfs(root, target);
        return ret;
    }
};