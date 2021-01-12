class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = {0, 1};
        vector<int> temp = {1};
        for (int i = 2; i <= num; i <<= 1) {
            int size = temp.size();
            for (int j = 0; j < size; ++j) {
                temp.push_back(temp[j] + 1);
            }
            for (int j = 0; j < size * 2; ++j) {
                ret.push_back(temp[j]);
            }
        }
        ret.erase(ret.begin() + num + 1, ret.end());
        return ret;
    }
};

// 0
// 1
// 1 2
