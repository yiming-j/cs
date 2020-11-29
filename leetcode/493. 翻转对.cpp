class Solution {
private:
    int mergeSort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) {
            return 0;
        }
        int mi = lo + (hi - lo) / 2;
        int n1 = mergeSort(nums, lo, mi);
        int n2 = mergeSort(nums, mi + 1, hi);
        int ans = n1 + n2;
        int i = lo, j = mi + 1;
        while (i <= mi) {
            while (j <= hi && (long long)nums[i] > 2 * (long long)nums[j]) {
                ++j;
            }
            ans += j - mi - 1;
            ++i;
        }
        
        vector<int> sorted(hi - lo + 1, 0);
        int p1 = lo, p2 = mi + 1, p = 0;
        while (p1 <= mi && p2 <= hi) {
            if (nums[p1] < nums[p2]) {
                sorted[p++] = nums[p1++];
            } else {
                sorted[p++] = nums[p2++];
            }
        }
        while (p1 <= mi) {
            sorted[p++] = nums[p1++];
        }
        while (p2 <= hi) {
            sorted[p++] = nums[p2++];
        }
        for (int i = 0; i < hi - lo + 1; ++i) {
            nums[lo + i] = sorted[i];
        }
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        return mergeSort(nums, 0, n - 1);
    }
};