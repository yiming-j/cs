class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<vector<int>> range;
        for (const auto &num : nums) {
            if (range.empty() || num > range.back().back() + 1) {
                range.push_back({num});
            } else {
                if (range.back().size() == 1) {
                    range.back().push_back(num);
                } else {
                    range.back()[1] = num;
                }
            }
        }
        vector<string> ret;
        for (const auto &r : range) {
            if (r.size() == 1) {
                ret.push_back(to_string(r[0]));
            } else {
                ret.push_back(to_string(r[0]) + "->" + to_string(r[1]));
            }
        }
        return ret;
    }
};