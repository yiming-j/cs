/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ret;
    
    void dfs(Node* root) {
        if (root == nullptr) {
            return;
        }
        for (const auto &child : root->children) {
            dfs(child);
        }
        ret.push_back(root->val);
    }
    
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return ret;
    }
};