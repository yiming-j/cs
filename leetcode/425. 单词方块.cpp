class Solution {
private:
    struct TrieNode {
        bool isWord;
        string word;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false), word("") {}
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
        node->isWord = true;
        node->word = word;
    }

    int n, l;
    vector<vector<string>> ret;
    
    void search(string &temp, TrieNode* root, int idx, const vector<TrieNode*> &nodes, vector<string> &temps) {
        if (temp.size() == l) {
            temps.push_back(temp);
            return;
        }
        for (const auto &kv : root->children) {
            if (nodes[idx]->children.count(kv.first)) {
                temp += kv.first;
                search(temp, kv.second, idx + 1, nodes, temps);
                temp.pop_back();
            }
        }
    }
    
    void dfs(vector<string> &strs, const vector<TrieNode*> &nodes) {
        if (strs.size() == l) {
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < l; ++j) {
                    if (strs[i][j] != strs[j][i]) {
                        return;
                    }
                }
            }
            ret.push_back(strs);
            return;
        }
        vector<string> temps;
        string temp;
        search(temp, root, 0, nodes, temps);
        for (const auto &temp : temps) {
            vector<TrieNode*> cnodes;
            for (int i = 0; i < l; ++i) {
                cnodes.push_back(nodes[i]->children[temp[i]]);
            }
            strs.push_back(temp);
            dfs(strs, cnodes);
            strs.pop_back();
        }
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words.size(), l = words[0].size();
        root = new TrieNode();
        for (const auto &word : words) {
            insert(word);
        }
        vector<TrieNode*> nodes(l, root);
        vector<string> strs;
        dfs(strs, nodes);
        return ret;
    }
};