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
    int predcessor(TreeNode* node) {
        node = node->left;
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }
    
    int successor(TreeNode* node) {
        node = node->right;
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                int succ = successor(root);
                root->val = succ;
                root->right = deleteNode(root->right, succ);
            } else {
                int pred = predcessor(root);
                root->val = pred;
                root->left = deleteNode(root->left, pred);
            }
        }
        return root;
    }
};