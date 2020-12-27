class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */