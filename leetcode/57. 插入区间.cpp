class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left = newInterval[0];
        int right = newInterval[1];
        bool flag = false;
        for (const auto &interval : intervals) {
            if (interval[1] < left) {
                ans.push_back(interval);
            } else if (interval[0] > right) {
                if (!flag) {
                    ans.push_back({left, right});
                    flag = true;
                }
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
                if (right > interval[1]) {
                    continue;
                } else {
                    ans.push_back({left, right});
                    flag = true;
                }
            }
        }
        if (!flag) {
            ans.push_back({left, right});
            flag = true;
        }
        return ans;
    }
};