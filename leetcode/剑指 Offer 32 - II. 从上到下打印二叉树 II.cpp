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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};