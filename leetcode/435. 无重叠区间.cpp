class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        int ret = 0;
        int end = INT_MIN;
        for (const auto &interval : intervals) {
            if (interval[0] < end) {
                ++ret;
                continue;
            }
            end = interval[1];
        }
        return ret;
    }
};