class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret{0};
        int add = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> temp(ret.rbegin(), ret.rend());
            for (auto &i : temp) {
                i += add;
                ret.push_back(i);
            }
            add <<= 1;
        }
        return ret;
    }
};