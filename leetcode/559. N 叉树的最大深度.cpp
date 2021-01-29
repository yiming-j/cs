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
    int dfs(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        for (const auto &child : root->children) {
            ret = max(ret, dfs(child));
        }
        return ret + 1;
    }
public:
    int maxDepth(Node* root) {
        return dfs(root);
    }
};