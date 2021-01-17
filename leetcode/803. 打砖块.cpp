class UFSet {
private:
    vector<int> parent;
    vector<int> sz;
public:
    UFSet(int n) {
        parent = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return;
        }
        if (pu > pv) {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        } else {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
    }
    
    int size(int u) {
        return sz[u];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        UFSet uf(m * n + 1);
        vector<vector<int>> status = grid;
        for (const auto &hit : hits) {
            status[hit[0]][hit[1]] = 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (status[i][j] == 1) {
                    if (i == 0) {
                        uf.merge(m * n, j);
                    } else {
                        if (j > 0 && status[i][j - 1] == 1) {
                            uf.merge(i * n + j - 1, i * n + j);                            
                        }
                        if (status[i - 1][j] == 1) {
                            uf.merge((i - 1) * n + j, i * n + j);
                        }
                    } 
                }
            }
        }
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        vector<int> ret(hits.size());
        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                continue;
            }
            status[r][c] = 1;
            int prev = uf.size(m * n);
            if (r == 0) {
                uf.merge(m * n, c);
            }
            for (int k = 0; k < 4; ++k) {
                int x = r + dx[k];
                int y = c + dy[k];
                if (x < 0 || x >= m || y < 0 || y >= n || status[x][y] == 0) {
                    continue;
                }
                uf.merge(x * n + y, r * n + c);
            }
            int curr = uf.size(m * n);
            ret[i] = max(0, curr - prev - 1);
        }
        return ret;
    }
};