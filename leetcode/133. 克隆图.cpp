/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> map;
    
    Node* dfs(Node* node) {
        if (node == nullptr) {
            return node;
        }
        if (map.count(node)) {
            return map[node];
        }
        Node* copy = new Node(node->val);
        map[node] = copy;
        for (auto n : node->neighbors) {
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};