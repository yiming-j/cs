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
    bool check(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }
        if (l == nullptr || r == nullptr) {
            return false;
        }
        return l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return check(root->left, root->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* l = q.front(); 
            q.pop();
            TreeNode* r = q.front(); 
            q.pop();
            
            if (l == nullptr && r == nullptr) {
                continue;
            }
            
            if (l == nullptr || r == nullptr || l->val != r->val) {
                return false;
            }
            
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};