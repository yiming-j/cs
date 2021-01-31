class Solution {
private:
    struct TrieNode {
        int idx;
        unordered_map<char, TrieNode*> children;
        TrieNode() : idx(-1) {}
        ~TrieNode() {
            for (const auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    TrieNode* root;
    
    void insert(const string &word, int idx) {
        TrieNode* node = root;
        for (const auto &c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->idx = idx;
    }
    
    int find(const string& word) {
        TrieNode* node = root;
        for (const auto &c : word) {
            if (!node->children.count(c)) {
                return -1;
            }
            node = node->children[c];
        }
        return node->idx;
    }
    
    bool isPalindrome(const string &str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i], i);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (isPalindrome(left)) {
                    reverse(right.begin(), right.end());
                    int l = find(right);
                    if (l != -1 && l != i) {
                        ret.push_back({l, i});
                    }
                }
                if (j < words[i].size() && isPalindrome(right)) {
                    reverse(left.begin(), left.end());
                    int r = find(left);
                    if (r != -1 && r != i) {
                        ret.push_back({i, r});
                    }
                }
            }
        }
        return ret;
    }
};