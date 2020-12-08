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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        int level = 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
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
            ans.push_back(temp);
            ++level;
        }
        return ans;        
    }
};