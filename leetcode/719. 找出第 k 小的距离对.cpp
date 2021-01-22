class Solution {
private:
    int count(vector<int>& nums, int mi) {
        int ret = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= mi) {
                ++j;
            }
            ret += j - i - 1;
        }
        return ret;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front();
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (count(nums, mi) < k) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (count(nums, lo) >= k) {
            return lo;
        }
        return hi;
    }
};