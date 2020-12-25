class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = INT_MIN;
        int maxValue = 1, minValue = 1;
        for (const auto &num : nums) {
            int prod1 = maxValue * num;
            int prod2 = minValue * num;
            maxValue = max({prod1, prod2, num});
            minValue = min({prod1, prod2, num});
            ret = max(ret, maxValue);
        }
        return ret;
    }
};