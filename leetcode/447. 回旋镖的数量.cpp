class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<unordered_map<int, int>> dists(points.size());
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) {
                    continue;
                }
                int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                ++dists[i][distance];
            }
        }
        int ret = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (const auto &kv : dists[i]) {
                if (kv.second >= 2) {
                    ret += kv.second * (kv.second - 1);
                }
            }
        }
        return ret;
    }
};