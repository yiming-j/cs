class Solution {
private:
    vector<vector<bool>> visited;
    vector<int> dx{-1, 0, 0, 1};
    vector<int> dy{0, -1, 1, 0};
    int m, n;
    
    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if (idx == word.size()) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[idx]) {
                continue;
            }
            visited[x][y] = true;
            if (dfs(board, x, y, word, idx + 1)) {
                return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size(), this->n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                visited[i][j] = true;
                if (dfs(board, i, j, word, 1)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
};