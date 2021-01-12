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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFindSet uf(s.size());
        for (const auto &pair : pairs) {
            uf.merge(pair[0], pair[1]);
        }
        unordered_map<int, deque<int>> map;
        for (int i = 0; i < s.size(); ++i) {
            map[uf.find(i)].push_back(i);
        }
        for (auto &[k, v] : map) {
            sort(v.begin(), v.end(), [&s] (const int &lhs, const int &rhs) {
                return s[lhs] < s[rhs];
            });
        }
        string ret;
        for (int i = 0; i < s.size(); ++i) {
            ret += s[map[uf.find(i)].front()];
            map[uf.find(i)].pop_front();
        }
        return ret;
    }
};