class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        vector<vector<int>> visited(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dx[j];
                    int y = p.second + dy[j];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] == 0) {
                        continue;
                    }
                    visited[x][y] = 1;
                    matrix[x][y] = dist;
                    q.push({x, y});
                }
            }
            ++dist;
        }
        return matrix;
    }
};