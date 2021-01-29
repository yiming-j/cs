class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [] (const auto &lhs, const auto &rhs) {
            string l = to_string(lhs), r = to_string(rhs);
            return l + r > r + l;
        });
        string ret;
        for (const auto &num : nums) {
            if (num == 0 && ret.empty()) {
                continue;
            }
            ret += to_string(num);
        }
        return ret.empty() ? "0" : ret;
    }
};