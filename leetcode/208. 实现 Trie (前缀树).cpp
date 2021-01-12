class Trie {
private:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        
        TrieNode() : isWord(false) {}
        ~TrieNode() {
            for (auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    TrieNode* root;
    
    const TrieNode* find(const string& s) const {
        TrieNode* node = root;
        for (const auto &c : s) {
            if (!node->children.count(c)) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() : root (new TrieNode()) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (const auto& c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode* node = find(word);
        return node && node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */