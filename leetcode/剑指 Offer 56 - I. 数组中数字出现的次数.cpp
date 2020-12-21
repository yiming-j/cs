class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (int num : nums) {
            temp ^= num;
        }
        int sign = temp ^ (temp & (temp - 1));
        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & sign) == sign) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};