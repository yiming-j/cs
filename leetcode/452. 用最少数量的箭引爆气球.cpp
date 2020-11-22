class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end());
        int n = points.size();
        int ans = 1;
        int end = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                ++ans;
                end = points[i][1];
            }
        }
        return ans;
    }
};