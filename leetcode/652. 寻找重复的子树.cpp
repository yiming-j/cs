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
    unordered_map<string, int> map;
    vector<TreeNode*> ret;
    
    string dfs(TreeNode* node) {
        if (node == nullptr) {
            return string("null");
        }
        string temp = to_string(node->val);
        temp = temp + " " + dfs(node->left) + " " + dfs(node->right);
        ++map[temp];
        if (map[temp] == 2) {
            ret.push_back(node);
        }        
        return temp;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ret;
    }
};