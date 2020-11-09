class Solution {
private:
    int divideConquer(vector<long long> &preSums, int lo, int hi, int lower, int upper) {
        if (lo == hi) {
            return 0;
        }
        int mi = lo + (hi - lo) / 2;
        int n1 = divideConquer(preSums, lo, mi, lower, upper);
        int n2 = divideConquer(preSums, mi + 1, hi, lower, upper);
        int ret = n1 + n2;
        
        int left = lo, right1 = mi + 1, right2 = mi + 1;
        while (left <= mi) {
            while (right1 <= hi && preSums[right1] - preSums[left] < lower) {
                ++right1;
            }
            while (right2 <= hi && preSums[right2] - preSums[left] <= upper) {
                ++right2;
            }
            ret += right2 - right1;
            ++left;
        }
        
        vector<long long>sorted(hi - lo + 1);
        int p = 0, p1 = lo, p2 = mi + 1;
        while (p1 <= mi && p2 <= hi) {
            if (preSums[p1] < preSums[p2]) {
                sorted[p++] = preSums[p1++];
            } else {
                sorted[p++] = preSums[p2++];
            }
        }
        while (p1 <= mi) {
            sorted[p++] = preSums[p1++];
        }
        while (p2 <= hi) {
            sorted[p++] = preSums[p2++];
        }
        for (int i = 0; i < p; ++i) {
            preSums[lo + i] = sorted[i];
        }
        return ret;
    } 
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> preSums{0};
        long long preSum = 0;
        for (const auto &num : nums) {
            preSum += num;
            preSums.push_back(preSum);
        }
        return divideConquer(preSums, 0, preSums.size() - 1, lower, upper);
    }
};