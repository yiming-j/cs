class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ans += 4;
                if (i > 0 && grid[i - 1][j] == 1) {
                    ans -= 2;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    ans -= 2;
                }
            }
        }
        return ans;
    }
};