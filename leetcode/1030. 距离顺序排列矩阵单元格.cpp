class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ans.push_back({i, j});
            }
        }
        sort(ans.begin(), ans.end(), 
             [&](const vector<int> &l, const vector<int> &r) {
                 return abs(l[0] - r0) + abs(l[1] - c0) < abs(r[0] - r0) + abs(r[1] - c0);
             });
        return ans;
    }
};

