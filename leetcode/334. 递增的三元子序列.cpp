class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int lo = INT_MAX, mi = INT_MAX;
        for (const int &num : nums) {
            if (num <= lo) {
                lo = num;
            } else if (num <= mi) {
                mi = num;
            } else {
                return true;
            }
        }
        return false;
    }
};