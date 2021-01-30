class AutocompleteSystem {
private:
    struct TrieNode {
        int count;
        string word;
        unordered_map<char, TrieNode*> children;
        TrieNode() : count(0), word("") {}
        ~TrieNode() {
            for (const auto &kv : children) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
    TrieNode* root;
    TrieNode* temp;
    string str;
    
    void insert(const string &word, int time) {
        TrieNode* node = root;
        for (const char &c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->count = time;
        node->word = word;
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        temp = root;
        str = "";
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            ++temp->count;
            if (temp->word == "") {
                temp->word = str;                
            }
            temp = root;
            str = "";
            return {};
        }
        str += c;
        if (!temp->children.count(c)) {
            temp->children[c] = new TrieNode();
            temp = temp->children[c];
            return {};
        }
        temp = temp->children[c];
        unordered_map<string, int> map;
        auto cmp = [&map] (const string &lhs, const string &rhs) {
            return map[lhs] == map[rhs] ? lhs < rhs : map[lhs] > map[rhs];
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        queue<TrieNode*> q;
        q.push(temp);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr->count) {
                map[curr->word] = curr->count;
                pq.push(curr->word);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
            for (const auto &kv : curr->children) {
                q.push(kv.second);
            }
        }
        vector<string> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */