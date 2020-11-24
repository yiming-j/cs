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
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        return left + right + 1;
    }
    
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};

class Solution {
private:
    bool exist(TreeNode* node, int idx, int depth) {
        int mask = 1 << (depth - 1);
        while (node && mask) {
            if (mask & idx) {
                node = node->right;
            } else {
                node = node->left;
            }
            mask >>= 1;
        }
        return node != nullptr;
    }
    
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return 1;
        }
        int depth = 0;
        TreeNode* curr = root;
        while (curr->left) {
            ++depth;
            curr = curr->left;
        }
        int lo = 1 << (depth), hi = (1 << (depth + 1)) - 1;
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (exist(root, mi, depth)) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (exist(root, hi, depth)) {
            return hi;
        }
        return lo;
    }
};