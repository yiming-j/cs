class Solution {
private:
    void mergeSort(vector<pair<int, int>> &nums, int lo, int hi, vector<int>& count) {
        if (lo >= hi) {
            return;
        }
        int mi = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mi, count);
        mergeSort(nums, mi + 1, hi, count);
        vector<pair<int, int>> temp(hi - lo + 1);
        int i = lo, j = mi + 1, k = 0;
        while (i <= mi && j <= hi) {
            while (j <= hi && nums[i].first > nums[j].first) {
                temp[k++] = nums[j++];
            }
            count[nums[i].second] += j - mi - 1;
            temp[k++] = nums[i++];
        }
        while (i <= mi) {
            count[nums[i].second] += j - mi - 1;
            temp[k++] = nums[i++];
        }
        while (j <= mi) {
            temp[k++] = nums[j++];
        }
        for (int i = 0; i < k; ++i) {
            nums[lo + i] = temp[i];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> nums_(n);
        vector<int> count(n);
        for (int i = 0; i < n; ++i) {
            nums_[i] = {nums[i], i};
        }
        mergeSort(nums_, 0, n - 1, count);
        return count;
    }
};