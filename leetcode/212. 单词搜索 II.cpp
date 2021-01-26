class Solution {
private:
    struct TrieNode {
        bool isWord;
        string word;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false), word("") {}
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
        node->isWord = true;
        node->word = word;
    }
    
    unordered_set<string> set;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};    
    vector<vector<int>> visited;
    int m, n;
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        if (node->isWord) {
            set.insert(node->word);
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || !node->children.count(board[x][y])) {
                continue;
            }
            visited[x][y] = 1;
            dfs(board, x, y, node->children[board[x][y]]);
            visited[x][y] = 0;
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const auto &word : words) {
            insert(word);
        }    
        m = board.size(), n = board[0].size();
        visited = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!root->children.count(board[i][j])) {
                    continue;
                }
                visited[i][j] = 1;
                dfs(board, i, j, root->children[board[i][j]]);
                visited[i][j] = 0;
            }
        }
        return vector<string>(set.begin(), set.end());
    }
};