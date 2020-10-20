class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (const auto &num: nums) {
            x ^= num;
        }
        return x;
    }
};