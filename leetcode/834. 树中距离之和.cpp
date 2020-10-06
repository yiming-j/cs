class Solution {
public:
    vector<int> dp, sz, ans;
    vector<vector<int>> adj;
    
    void dfs_root(int u, int p) {
        dp[u] = 0;
        sz[u] = 1;
        for (const auto& v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs_root(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }
    
    void dfs_dist(int u, int p) {
        ans[u] = dp[u];
        for (const auto& v : adj[u]) {
            if (v == p) {
                continue;
            }
            int dp_u = dp[u], dp_v = dp[v];
            int sz_u = sz[u], sz_v = sz[v];
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
            
            dfs_dist(v, u);
            
            dp[u] = dp_u;
            dp[v] = dp_v;
            sz[u] = sz_u;
            sz[v] = sz_v;
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        dp.resize(N, 0);
        sz.resize(N, 0);
        ans.resize(N, 0);
        adj.resize(N, {});
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs_root(0, -1);
        dfs_dist(0, -1);
        return ans;
    }
};