class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        vector<int> visited(m * n);
        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        auto cmp = [] (const vector<int>& lhs, const vector<int>& rhs) {
            // [x, y, dist]
            return lhs[2] > rhs[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int idx = node[0] * n + node[1];
            if (visited[idx]) {
                continue;
            }
            if (node[0] == m - 1 && node[1] == n - 1) {
                break;
            }
            visited[idx] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = node[0] + dx[k];
                int y = node[1] + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x * n + y]) {
                    continue;
                }
                int distance = max(node[2], abs(heights[x][y] - heights[node[0]][node[1]]));
                if (distance < dist[x * n + y]) {
                    dist[x * n + y] = distance;
                    pq.push({x, y, distance});
                }
            }
        }
        return dist[m * n - 1];
    }
};