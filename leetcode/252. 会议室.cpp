class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = -1;
        for (const auto &interval : intervals) {
            if (interval[0] < end) {
                return false;
            }
            end = max(end, interval[1]);
        }
        return true;
    }
};