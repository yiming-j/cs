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
    int diameter = 0;
public:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        diameter = max(diameter, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};