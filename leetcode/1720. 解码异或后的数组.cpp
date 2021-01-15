class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret{first};
        for (const auto &encode : encoded) {
            ret.push_back(encode ^ ret.back());
        }
        return ret;
    }
};