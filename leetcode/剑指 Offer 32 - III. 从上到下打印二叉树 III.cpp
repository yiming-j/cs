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
        deque<TreeNode*> dq;
        dq.push_back(root);
        vector<vector<int>> ret;
        int level = 0;
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                if (level % 2 == 0) {
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    temp.push_back(curr->val);
                    if (curr->left) {
                        dq.push_back(curr->left);
                    }
                    if (curr->right) {
                        dq.push_back(curr->right);
                    }
                } else {
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    temp.push_back(curr->val);
                    if (curr->right) {
                        dq.push_front(curr->right);
                    }
                    if (curr->left) {
                        dq.push_front(curr->left);
                    }
                }
            }
            ret.push_back(temp);
            ++level;
        }
        return ret;
    }
};