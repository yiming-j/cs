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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UFSet ufs(n);
        for (const auto &oneSwap : allowedSwaps) {
            ufs.merge(oneSwap[0], oneSwap[1]);
        }
        unordered_map<int, unordered_multiset<int>> s, t;
        for (int i = 0; i < n; ++i) {
            int pi = ufs.find(i);
            s[pi].insert(source[i]);
            t[pi].insert(target[i]);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (ufs.find(i) != i) {
                continue;
            }
            for (const auto &x : s[i]) {
                if (t[i].find(x) == t[i].end()) {
                    ++ret;
                } else {
                    t[i].erase(t[i].find(x));
                }
            }
        }
        return ret;
    }
};