class UFSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UFSet(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
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
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            ++rank[pu];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UFSet uf(n * n * 4);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j;
                if (i < n - 1) {
                    uf.merge(idx * 4 + 2, (idx + n) * 4);
                }
                if (j < n - 1) {
                    uf.merge(idx * 4 + 1, (idx + 1) * 4 + 3);
                }
                if (grid[i][j] == '/') {
                    uf.merge(idx * 4 + 1, idx * 4 + 2);
                    uf.merge(idx * 4, idx * 4 + 3);
                } else if (grid[i][j] == '\\') {
                    uf.merge(idx * 4, idx * 4 + 1);
                    uf.merge(idx * 4 + 2, idx * 4 + 3);
                } else {
                    uf.merge(idx * 4, idx * 4 + 1);
                    uf.merge(idx * 4 + 1, idx * 4 + 2);
                    uf.merge(idx * 4 + 2, idx * 4 + 3);
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n * n * 4; ++i) {
            set.insert(uf.find(i));
        }
        return set.size();
    }
};