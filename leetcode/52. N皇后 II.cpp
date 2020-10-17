class Solution {
private:
    int size;
    vector<vector<int>> direction{{1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> grid;
    int ans;
    
public:
    void dfs(int i) {
        if (i == size) {
            ++ans;
            return;
        }
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] > 0) {
                continue;
            }
            mark(i, j, 1);
            dfs(i + 1);
            mark(i, j, -1);
        }
    }
    
    void mark(int i, int j, int flag) {
        grid[i][j] += flag;
        for (const auto &delta : direction) {
            int x = i + delta[0];
            int y = j + delta[1];
            while (x >= 0 && x < size && y >= 0 && y < size) {
                grid[x][y] += flag;
                x += delta[0];
                y += delta[1];
            }
        }
    }
    
    int totalNQueens(int n) {
        size = n;
        grid.resize(n, vector<int>(n, 0));
        dfs(0);
        return ans;
    }
};