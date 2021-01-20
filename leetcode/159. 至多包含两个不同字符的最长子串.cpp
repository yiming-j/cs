class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ret = 0;
        int i = 0, j = 0;
        unordered_map<char, int> map;
        while (j < s.size()) {
            while (j < s.size() && (map.size() < 2 || (map.size() == 2 && map.count(s[j])))) {
                ++map[s[j]];
                ++j;
            }
            ret = max(ret, j - i);
            while (map.size() >= 2) {
                if (--map[s[i]] == 0) {
                    map.erase(s[i]);
                }
                ++i;
            }
        }
        return ret;
    }
};