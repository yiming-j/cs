class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = INT_MIN;
        int i = 0, j = 0;
        int curr = 0;
        while (j < nums.size()) {
            while (j - i < k && j < nums.size()) {
                curr += nums[j++];
            }
            sum = max(sum, curr);
            curr -= nums[i++];
        }
        return (double)sum / k;
    }
};