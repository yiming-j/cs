class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int num = 0;
        for (const auto &a : A) {
            num = ((num << 1) + a) % 5;
            ret.push_back(num == 0);
        }
        return ret;
    }
};