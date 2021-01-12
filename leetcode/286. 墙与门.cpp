class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        vector<vector<int>> visited(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] != 0) {
                    continue;
                }
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
        int distance = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = curr.first + dx[j];
                    int y = curr.second + dy[j];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || rooms[x][y] <= 0) {
                        continue;
                    }
                    visited[x][y] = 1;
                    rooms[x][y] = min(rooms[x][y], distance);
                    q.push({x, y});
                }
            }
            ++distance;
        }
    }
};