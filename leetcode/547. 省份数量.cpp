class UnionFindSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFindSet(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int Find(int u) {
        if (u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }
    
    void Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv) {
            return;
        }
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            ++rank[pu];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFindSet ufset(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    ufset.Union(i, j);
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            set.insert(ufset.Find(i));
        }
        return set.size();
    }
};