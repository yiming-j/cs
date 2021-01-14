class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int target = image[sr][sc];
        queue<pair<int, int>> q;
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        int m = image.size(), n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        q.push({sr, sc});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = curr.first + dx[k];
                int y = curr.second + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || image[x][y] != target) {
                    continue;
                }
                image[x][y] = newColor;
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
        return image;
    }
};

