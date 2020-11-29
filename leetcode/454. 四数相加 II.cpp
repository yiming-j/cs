class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        for (const auto &a : A) {
            for (const auto &b : B) {
                ++map[a + b];
            }
        }
        int ans = 0;
        for (const auto &c : C) {
            for (const auto &d : D) {
                if (map.count(- c - d)) {
                    ans += map[- c - d];
                }
            }
        }
        return ans;
    }
};