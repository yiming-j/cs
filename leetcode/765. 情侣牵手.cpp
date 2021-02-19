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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UFSet ufs(n / 2);
        for (int i = 0; i < n; i += 2) {
            if (row[i] / 2 == row[i + 1] / 2) {
                continue;
            }
            ufs.merge(row[i] / 2, row[i + 1] / 2);
        }
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            ++map[ufs.find(row[i] / 2)];
        }
        int ret = 0;
        for (const auto &it : map) {
            ret += it.second / 2 - 1;
        }
        return ret;
    }
};