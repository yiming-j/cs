class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        int ans = 0;
        int n = timeSeries.size();
        int end = timeSeries[0] + duration - 1;
        for (int i = 1; i < n; ++i) {
            if (end < timeSeries[i]) {
                ans += duration;
            } else {
                ans += timeSeries[i] - timeSeries[i - 1];
            }
            end = timeSeries[i] + duration - 1;
        }
        ans += duration;
        return ans;
    }
};