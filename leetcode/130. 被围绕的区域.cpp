class UFSet {
private:
    vector<int> parent;

public:
    UFSet(int n) {
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return;
        }
        if (pu > pv) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        vector<int> dx = {-1, 0};
        vector<int> dy = {0, -1};
        int m = board.size(), n = board[0].size();
        UFSet uf(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != 'O') {
                    continue;
                } 
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.merge(m * n, i * n + j);
                }
                for (int k = 0; k < 2; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
                        continue;
                    } 
                    uf.merge(x * n + y, i * n + j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && uf.find(i * n + j) != m * n) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};