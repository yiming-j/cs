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
private:
    bool isSimilar(const string &lhs, const string &rhs) {
        int count = 0;
        for (int i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) {
                ++count;
            }
        }
        return count == 0 || count == 2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, int> map;
        for (int i = 0; i < n; ++i) {
            map[strs[i]] = i;
        }
        UFSet uf(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.merge(i, j);
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            set.insert(uf.find(i));
        }
        return set.size();
    }
};