/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }
        string ans = "[";
        queue<TreeNode*> q;
        q.push(root);
        string nullTemp = "";
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                nullTemp += "null,";
                continue;
            }
            ans += nullTemp;
            nullTemp = "";
            ans += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }
        ans.pop_back();
        ans += ']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") {
            return nullptr;
        }
        int n = data.size();
        int i = 1;
        string rootStr = "";
        while (data[i] != ',' && data[i] != ']') {
            rootStr += data[i];
            ++i;
        }
        TreeNode* root = new TreeNode(stoi(rootStr));
        queue<TreeNode*> q;
        q.push(root);
        ++i;
        while (i < n) {
            TreeNode* curr = q.front();
            q.pop();
            string ls = "";
            while (i < n && data[i] != ',' && data[i] != ']') {
                ls += data[i];
                ++i;
            }
            if (ls == "null" || ls == "") {
                curr->left = nullptr;
            } else {
                curr->left = new TreeNode(stoi(ls));
                q.push(curr->left);
            }
            ++i;
            
            string rs = "";
            while (i < n && data[i] != ',' && data[i] != ']') {
                rs += data[i];
                ++i;
            }
            if (rs == "null" || rs == "") {
                curr->right = nullptr;
            } else {
                curr->right = new TreeNode(stoi(rs));
                q.push(curr->right);
            }
            ++i;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));