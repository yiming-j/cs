class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), 
             [](const vector<int> &l, const vector<int> &r) {
                 return l[0] < r[0];
             });
        int start = 0, end = 0;
        int ans = 0;
        for (const auto &clip: clips) {
            if (clip[0] > end) {
                return -1;
            }
            if (clip[0] > start) {
                ++ans;
                start = end;
            }
            end = max(end, clip[1]);
            if (end >= T) {
                ++ans;
                break;
            }
        }
        return end < T ? -1 : ans;
    }
};