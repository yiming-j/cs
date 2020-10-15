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
    void dfs(TreeNode* node, vector<int> &ans) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans{root->val};
        TreeNode* left = root->left;
        while (left) {
            ans.push_back(left->val);
            if (left->left) {
                left = left->left;
            } else if (left->right) {
                left = left->right;
            } else {
                left = nullptr;
            }
        }
        if (ans.size() > 1) {
            ans.pop_back();
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
        TreeNode* right = root->right;
        stack<int> r_border;
        while (right) {
            r_border.push(right->val);
            if (right->right) {
                right = right->right;
            } else if (right->left) {
                right = right->left;
            } else {
                right = nullptr;
            }
        }
        if (!r_border.empty()) {
            r_border.pop();
        }
        while (!r_border.empty()) {
            ans.push_back(r_border.top());
            r_border.pop();
        }
        return ans;
    }
};