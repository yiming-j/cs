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
    struct Edge {
        int len;
        int start;
        int end;
        Edge(int l, int s, int e) : len(l), start(s), end(e) {}
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto dist = [&points] (const int &lhs, const int &rhs) {
            return abs(points[lhs][0] - points[rhs][0]) + abs(points[lhs][1] - points[rhs][1]);
        };
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [] (const Edge &lhs, const Edge &rhs) {
            return lhs.len < rhs.len;
        });
        UFSet ufs(n);
        int count = 0;
        int ret = 0;
        for (const auto &edge : edges) {
            if (ufs.find(edge.start) != ufs.find(edge.end)) {
                ufs.merge(edge.start, edge.end);
                ret += edge.len;
                if (++count == n - 1) {
                    break;
                }
            }
        }
        return ret;
    }
};