class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.begin(), digits.end());
        int carry = 0;
        int size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            ans[i] += 1;
            carry = ans[i] / 10;
            ans[i] %= 10;
            if (carry == 0) {
                break;
            }
        }
        if (carry == 1) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};