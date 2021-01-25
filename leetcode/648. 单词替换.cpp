class Solution {
private:
    struct TrieNode {
        bool isRoot;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isRoot(false) {}
        ~TrieNode() {
            for (const auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    TrieNode* root;
    
    void insert(const string &word) {
        TrieNode* node = root;
        for (const auto &c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isRoot = true;
    }
    
    string findRoot(const string& word) {
        TrieNode* node = root;
        string ret;
        for (const auto &c : word) {
            if (!node->children[c]) {
                return word;
            }
            node = node->children[c];
            ret += c;
            if (node->isRoot) {
                break;
            }
        }
        return ret;
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for (const auto &word : dictionary) {
            insert(word);
        }
        string temp;
        string ret;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                ret += findRoot(temp) + ' ';
                temp = "";
                continue;
            }
            temp += sentence[i];
        }
        ret += findRoot(temp);
        return ret;
    }
};