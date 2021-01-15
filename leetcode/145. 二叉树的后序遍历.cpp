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
    vector<int> ret;
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        ret.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ret;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        TreeNode* prev = nullptr;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            if (root->right == nullptr || root->right == prev) {
                ret.push_back(root->val);
                prev = root;
                root = nullptr;
                stk.pop();
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};