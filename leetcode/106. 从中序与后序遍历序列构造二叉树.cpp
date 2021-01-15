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
    
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int ilo, int ihi, int plo, int phi) {
        if (ilo > ihi) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[phi]);
        int imi = map[postorder[phi]] - 1;
        int pmi = plo + imi - ilo;
        root->left = build(inorder, postorder, ilo, imi, plo, pmi);
        root->right = build(inorder, postorder, imi + 2, ihi, pmi + 1, phi - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};