class Solution {
private:
    int search(vector<int>& len, int lo, int hi, int target) {
        while (lo + 1 < hi) {
            int mi = lo + (hi - lo) / 2;
            if (len[mi] < target) {
                lo = mi;
            } else {
                hi = mi;
            }
        }
        if (target <= len[lo]) {
            return lo;
        }
        if (target <= len[hi]) {
            return hi;
        }
        return hi + 1;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> len{nums[0]};
        int lo = 0, hi = 0;
        for (int i = 1; i < n; ++i) {
            int idx = search(len, lo, hi, nums[i]);
            if (idx == hi + 1) {
                len.push_back(nums[i]);
                ++hi;
            } else {
                len[idx] = nums[i];
            }
        }
        return len.size();
    }
};