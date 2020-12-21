class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int curr = 0;
        for (int &num : nums) {
            curr = max(curr + num, num);
            ret = max(ret, curr);
        }
        return ret;
    }
};