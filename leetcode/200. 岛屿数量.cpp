class Solution {
private:
    vector<vector<int>> d{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                ++ans;
                grid[i][j] = '0';
                q.push({i, j});
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = curr.first + d[k][0];
                        int y = curr.second + d[k][1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
                            continue;
                        }
                        grid[x][y] = '0';
                        q.push({x, y});
                    }
                }
            }
        }
        return ans;
    }
};