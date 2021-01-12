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
    unordered_map<TreeNode*, unordered_map<int, int>> map;
    int sum;
    int ret = 0;
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        map[node][node->val] = 1;
        if (map.find(node->left) != map.end()) {
            for (const auto &kv : map[node->left]) {
                map[node][node->val + kv.first] += kv.second;
            }
        }
        if (map.find(node->right) != map.end()) {
            for (const auto &kv : map[node->right]) {
                map[node][node->val + kv.first] += kv.second;
            }
        }
        for (const auto &kv : map[node]) {
            if (kv.first == sum) {
                ret += kv.second;
            }
        }
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        this->sum = sum;
        dfs(root);
        return ret;
    }
};

class Solution {
private:
    int dfs(TreeNode* node, int sum) {
        if (node == nullptr) {
            return 0;
        }
        int ret = node->val == sum;
        return ret + dfs(node->left, sum - node->val) + dfs(node->right, sum - node->val);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        int ret = dfs(root, sum);
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        return ret + left + right;
    }
};