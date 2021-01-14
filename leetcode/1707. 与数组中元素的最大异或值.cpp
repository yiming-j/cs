class Trie {
private:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() : children{nullptr, nullptr} {}
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
    
    int xorQuery(int x) {
        TrieNode* node = root;
        int ret = 0;
        for (int i = 31; i >= 0; --i) {
            if (!node) {
                return -1;
            }
            int bit = (x >> i) & 1;
            if (node->children[1 - bit]) {
                ret |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), Q = queries.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < Q; ++i) {
            queries[i].push_back(i);
        }
        sort(begin(queries), end(queries), [] (const auto &lhs, const auto &rhs) {
            return lhs[1] < rhs[1];
        });
        Trie trie;
        vector<int> ret(Q);
        int i = 0;
        for (const auto &q : queries) {
            while (i < N && nums[i] <= q[1]) {
                trie.insert(nums[i++]);
            }
            ret[q[2]] = trie.xorQuery(q[0]);
        }
        return ret;
    }
};