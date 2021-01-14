class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        TrieNode() : children(2) {}
        ~TrieNode() {
            for (auto &c : children) {
                if (c) {
                    delete c;
                }
            }
        }
    };
    
    TrieNode* root;
    
public:
    Trie() : root(new TrieNode()) {}
    void insert(int x) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();                
            }
            node = node->children[bit];
        }
    }
    
    int query(int x) {
        TrieNode* node = root;
        int ret = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (node->children[1 - bit]) {
                ret |= (1 << i);
                node = node->children[1 - bit];
            } else if (node->children[bit]) {
                node = node->children[bit];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ret = 0;
        Trie t;
        for (const int &num : nums) {
            ret = max(ret, t.query(num));
            t.insert(num);
        }
        return ret;
    }
};