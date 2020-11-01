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
private:
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        int mi = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(nums[mi]);
        node->left = helper(nums, lo, mi - 1);
        node->right = helper(nums, mi + 1, hi);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};