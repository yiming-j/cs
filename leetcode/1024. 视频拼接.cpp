class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxR(T);
        for (auto &clip : clips) {
            if (clip[0] >= T) {
                continue;
            }
            maxR[clip[0]] = max(maxR[clip[0]], clip[1]);
        }
        int ret = 0;
        int prevEnd = 0, end = 0;
        for (int i = 0; i < T; ++i) {
            end = max(end, maxR[i]);
            if (i == end) {
                return -1;
            }
            if (i == prevEnd) {
                ++ret;
                prevEnd = end;
            }
        }
        return ret;
    }
};