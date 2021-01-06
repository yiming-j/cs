class UnionFindSet {
public:
    UnionFindSet(int n) {
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int Find(int u) {
        if (parent[u] != u) {
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
    
private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet ufset(edges.size());
        for (const auto &edge : edges) {
            if (ufset.Find(edge[0]) != ufset.Find(edge[1])) {
                ufset.Union(edge[0], edge[1]);
            } else {
                return edge;
            }
        }
        return {};
    }
};