class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        } 
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<pair<int, int>> bucket(bucketSize, {-1, -1});
        for (int i = 0; i < n; ++i) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = nums[i];
                bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }
        int ans = 0;
        int prevIdx = 0;
        for (int i = 1; i < bucketSize; ++i) {
            if (bucket[i].first == -1) {
                continue;
            }
            if (bucket[prevIdx].first != -1) {
                ans = max(ans, bucket[i].first - bucket[prevIdx].second);  
            }
            prevIdx = i;
        }
        return ans;
    }
};