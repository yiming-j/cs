class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ret(n, -1);
        for (int j = 0; j < n; ++j) {
            int x = 0, y = j;
            while (x < m) {
                if (grid[x][y] == 1) {
                    if (y == n - 1 || grid[x][y + 1] == -1) {
                        break;
                    }
                    ++x;
                    ++y;
                } else {
                    if (y == 0 || grid[x][y - 1] == 1) {
                        break;
                    }
                    ++x;
                    --y;
                }
            }
            if (x == m) {
                ret[j] = y;
            }
        }
        return ret;
    }
};