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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1, curr = -1, min_diff = INT_MAX;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                s.pop();
                curr = root->val;
                if (prev == -1) {
                    prev = curr - INT_MAX;
                }
                min_diff = min(curr - prev, min_diff);
                prev = curr;
                root = root->right;
            }
        }
        return min_diff;
    }
};