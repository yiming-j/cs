class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int size = s.size();
        int i = 0, j = 0;
        vector<int> pos(128, -1);
        while (j < size) {
            while (j < size && pos[s[j]] < i) {
                pos[s[j]] = j;
                ++j;
            }
            ans = max(ans, j - i);
            i = max(i, pos[s[i]] + 1);
        }
        return ans;
    }
};