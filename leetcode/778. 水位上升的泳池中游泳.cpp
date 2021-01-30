class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        int n = grid.size();
        vector<int> dist(n * n, INT_MAX);
        vector<int> visited(n * n);
        dist[0] = grid[0][0];
        auto cmp = [] (const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[2] > rhs[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, dist[0]});
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int idx = node[0] * n + node[1];
            if (visited[idx]) {
                continue;
            }
            if (idx == n * n - 1) {
                break;
            }
            visited[idx] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = node[0] + dx[k];
                int y = node[1] + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= n || visited[x * n + y]) {
                    continue;
                }
                int distance = max(node[2], grid[x][y]);
                if (distance < dist[x * n + y]) {
                    dist[x * n + y] = distance;
                    pq.push({x, y, distance});
                }
            }
        }
        return dist[n * n - 1];
    }
};