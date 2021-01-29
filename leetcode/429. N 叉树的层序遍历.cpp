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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                temp.push_back(node->val);
                q.pop();
                for (const auto &child : node->children) {
                    q.push(child);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};