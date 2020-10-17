class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<string>> ans;
    vector<vector<int>> delta{{1, 0}, {1, 1}, {1, -1}};
    int size;
    
public:
    void dfs(int i, vector<string> &solution) {
        if (i == size) {
            ans.push_back(solution);
            return;
        }
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] > 0) {
                continue;
            }
            solution[i][j] = 'Q';
            mark(i, j, 1);
            dfs(i + 1, solution);
            mark(i, j, -1);
            solution[i][j] = '.';
        }
    }
    
    void mark(int i, int j, int flag) {
        grid[i][j] += flag;
        for (const auto &d : delta) {
            int x = i + d[0];
            int y = j + d[1];
            while (x >= 0 && x < size && y >= 0 && y < size) {
                grid[x][y] += flag;
                x += d[0];
                y += d[1];
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        grid.resize(size, vector<int>(size));
        vector<string> solution(size, string(size, '.'));
        dfs(0, solution);
        return ans;
    }
};