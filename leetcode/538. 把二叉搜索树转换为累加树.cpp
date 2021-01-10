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
    int sum = 0;
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->right);
        node->val += sum;
        sum = node->val;
        dfs(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> stk;
        int sum = 0;
        while (!stk.empty() || node) {
            while (node) {
                stk.push(node);
                node = node->right;
            }
            node = stk.top();
            stk.pop();
            node->val += sum;
            sum = node->val;
            node = node->left;
        }
        return root;
    }
};