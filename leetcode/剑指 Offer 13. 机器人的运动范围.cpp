class Solution {
private:
    int getSum(int x) {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
    
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> d{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        int ret = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = pos.first + d[i][0];
                int y = pos.second + d[i][1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || getSum(x) + getSum(y) > k) {
                    continue;
                }
                visited[x][y] = true;
                q.push({x, y});
                ++ret;
            }
        }
        return ret;
    }
};