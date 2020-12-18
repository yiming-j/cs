class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int ans = 0;
        for (int k : set) {
            if (set.count(k - 1)) {
                continue;
            }
            int len = 1;
            while (set.count(k + 1)) {
                ++k;
                ++len;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};