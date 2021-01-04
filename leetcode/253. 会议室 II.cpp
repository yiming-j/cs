class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        auto cmp = [] (const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] > rhs[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (const auto &interval : intervals) {
            if (!pq.empty() && pq.top()[1] <= interval[0]) {
                pq.pop();
            }
            pq.push(interval);
        }
        return pq.size();
    }
};