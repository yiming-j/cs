class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<int>> d{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if (board[x][y] == 1 || board[x][y] == -1) {
                        ++count;
                    }
                }
                if (board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = -1;
                }
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 2;
                }  
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};