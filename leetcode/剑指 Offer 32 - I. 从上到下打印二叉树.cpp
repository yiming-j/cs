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
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        return ans;
    }
};