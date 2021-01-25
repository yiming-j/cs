class MapSum {
private:
    struct TrieNode {
        int val;
        unordered_map<char, TrieNode*> children;
        TrieNode() : val(0) {}
        ~TrieNode() {
            for (auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    TrieNode* root;
    
    void dfs(TrieNode* node, int& ret) {
        ret += node->val;
        if (node->children.empty()) {
            return;
        }
        for (const auto &kv : node->children) {
            dfs(kv.second, ret);
        }
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        for (const auto &c : key) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for (const auto &c : prefix) {
            if (!node->children.count(c)) {
                return 0;
            }
            node = node->children[c];
        }
        int ret = 0;
        dfs(node, ret);
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */