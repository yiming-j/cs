class UFSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UFSet (int n) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UFSet Alice(n + 1), Bob(n + 1);
        int countA = n - 1, countB = n - 1;
        int ret = 0;
        for (const auto &edge : edges) {
            if (edge[0] != 3) {
                continue;
            }
            if (Alice.find(edge[1]) != Alice.find(edge[2])) {
                Alice.merge(edge[1], edge[2]);
                Bob.merge(edge[1], edge[2]);
                --countA;
                --countB;
            } else {
                ++ret;
            }
        }
        for (const auto &edge : edges) {
            if (edge[0] == 1) {
                if (Alice.find(edge[1]) != Alice.find(edge[2])) {
                    Alice.merge(edge[1], edge[2]);
                    --countA;
                } else {
                    ++ret;
                }
            } else if (edge[0] == 2) {
                if (Bob.find(edge[1]) != Bob.find(edge[2])) {
                    Bob.merge(edge[1], edge[2]);
                    --countB;
                } else {
                    ++ret;
                }
            }
        }
        return countA == 0 && countB == 0 ? ret : -1;
    }
};