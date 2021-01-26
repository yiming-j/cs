class WordDictionary {
private:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false) {}
        ~TrieNode() {
            for (const auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    bool search(TrieNode* node, const string &word, int start) {
        if (start == word.size()) {
            return node->isWord;
        }
        bool ret = false;
        if (word[start] == '.') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (node->children.count(c)) {
                    ret |= search(node->children[c], word, start + 1);
                }
            }
        } else {
            if (node->children.count(word[start])) {
                ret = search(node->children[word[start]], word, start + 1);
            }
        }
        return ret;
    }
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (const auto &c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                return search(node, word, i);
            }
            if (!node->children.count(word[i])) {
                return false;
            }
            node = node->children[word[i]];
        }
        return node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */