class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i) {
            ans[i] = a[i - 1] * ans[i - 1];
        }
        int r = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= r;
            r *= a[i];
        }
        return ans;
    }
};