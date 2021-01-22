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
    vector<vector<vector<TreeNode*>>> dp;
    
    vector<TreeNode*> dfs(int lo, int hi) {
        if (lo > hi) {
            return {nullptr};
        }
        if (lo == hi) {
            dp[lo][hi] = {new TreeNode(lo)};
        }
        if (!dp[lo][hi].empty()) {
            return dp[lo][hi];
        }
        for (int mi = lo; mi <= hi; ++mi) {
            auto lefts = dfs(lo, mi - 1);
            auto rights = dfs(mi + 1, hi);
            for (const auto &left : lefts) {
                for (const auto &right : rights) {
                    TreeNode* root = new TreeNode(mi);
                    root->left = left;
                    root->right = right;
                    dp[lo][hi].push_back(root);
                }
            }
        }
        return dp[lo][hi];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        dp.resize(n + 1, vector<vector<TreeNode*>>(n + 1));
        return dfs(1, n);
    }
};