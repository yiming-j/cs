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
    int removeStones(vector<vector<int>>& stones) {
        UnionFindSet uf(20002);
        for (const auto &stone : stones) {
            uf.merge(stone[0], 10001 + stone[1]);
        }
        unordered_set<int> set;
        for (const auto &stone : stones) {
            set.insert(uf.find(stone[0]));
        }
        return stones.size() - set.size();
    }
};