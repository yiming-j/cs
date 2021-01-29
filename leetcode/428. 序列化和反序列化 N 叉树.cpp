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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) {
            return "";
        }
        string ret = to_string(root->val) + ' ';
        if (!root->children.empty()) {
            ret += "[";
            for (const auto &child : root->children) {
                ret += serialize(child);
            }
            ret += ']';
        }
        return ret;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        int val = 0;
        int i = 0;
        for (; i < data.size() && isdigit(data[i]); ++i) {
            val = val * 10 + data[i] - '0';
        }
        Node* root = new Node(val);
        val = 0;
        ++i;
        Node* node = root;
        stack<Node*> stk;
        for (; i < data.size(); ++i) {
            if (isdigit(data[i])) {
                val = val * 10 + data[i] - '0';
            } else if (data[i] == '[') {
                stk.push(node);
            } else if (data[i] == ']') {
                stk.pop();
            } else if (data[i] == ' ') {
                node = new Node(val);
                val = 0;
                stk.top()->children.push_back(node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));