class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n, true);
        for (int i = 0; i < n; ++i) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            for (int j = 1; j < temp.size(); ++j) {
                if (temp[j] - temp[j - 1] != diff) {
                    ans[i] = false;
                }
            }
        }
        return ans;
    }
};