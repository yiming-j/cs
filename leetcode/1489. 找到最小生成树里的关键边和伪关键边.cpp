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
private:
    int MST(int n, vector<vector<int>> &edges, int idx, bool add) {
        UFSet uf(n);
        int ret = 0;
        if (add) {
            uf.merge(edges[idx][0], edges[idx][1]);
            ret += edges[idx][2];
            --n;
        }
        for (int i = 0; i < edges.size() && n > 1; ++i) {
            if (i == idx) {
                continue;
            }
            if (uf.find(edges[i][0]) == uf.find(edges[i][1])) {
                continue;
            }
            uf.merge(edges[i][0], edges[i][1]);
            ret += edges[i][2];
            --n;
        }
        return n == 1 ? ret : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[2] < rhs[2];
        });
        int minWeight = MST(n, edges, -1, false);
        vector<vector<int>> ret(2);
        for (int i = 0; i < edges.size(); ++i) {
            int subWeight = MST(n, edges, i, false);
            if (subWeight > minWeight) {
                ret[0].push_back(edges[i][3]);
            } else {
                int addWeight = MST(n, edges, i, true);
                if (addWeight == minWeight) {
                    ret[1].push_back(edges[i][3]);
                }                
            }
        }
        return ret;
    }
};