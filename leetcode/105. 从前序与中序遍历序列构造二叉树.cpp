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
    unordered_map<int, int> map;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int plo, int phi, int ilo, int ihi) {
        if (plo > phi) {
            return nullptr;
        } 
        TreeNode* root = new TreeNode(preorder[plo]);
        int imi = map[preorder[plo]];
        int pmi = plo + 1 + imi - ilo;
        root->left = build(preorder, inorder, plo + 1, pmi - 1, ilo, imi - 1);
        root->right = build(preorder, inorder, pmi, phi, imi + 1, ihi);
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            map[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};