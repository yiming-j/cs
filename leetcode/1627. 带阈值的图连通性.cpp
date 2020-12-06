class Solution {
private:
    vector<int> p;
public:
    int find(int c) {
        if (c != p[c]) {
            p[c] = find(p[c]);
        }
        return p[c];
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        p.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        for (int i = threshold + 1; i <= n; ++i) {
            if (p[i] != i) {
                continue;
            }
            for (int j = 2 * i; j <= n; j += i) {
                p[find(j)] = i;
            }
        }
        vector<bool> ans;
        for (const auto &query : queries) {
            ans.emplace_back(find(query[0]) == find(query[1]));
        }
        return ans;
    }
};