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
    bool dfs(TreeNode* node, long long lo, long long hi) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= lo || node->val >= hi) {
            return false;
        }
        return dfs(node->left, lo, node->val) && dfs(node->right, node->val, hi);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long prev = LONG_MIN;
        while (root != nullptr || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            int curr = root->val;
            if (curr <= prev) {
                return false;
            }
            prev = curr;
            root = root->right;
        }
        return true;
    }
};