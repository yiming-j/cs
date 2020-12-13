class Solution {
private:
    int m, n, w;
    vector<vector<bool>> visited;
    vector<vector<int>> d{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool dfs(vector<vector<char>>& board, string& word, int s, int i, int j) {
        if (s == w) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + d[k][0];
            int y = j + d[k][1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true || board[x][y] != word[s]) {
                continue;
            }
            visited[x][y] = true;
            if (dfs(board, word, s + 1, x, y)) {
                return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        this->m = m, this->n = n, this->w = word.size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(board, word, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};