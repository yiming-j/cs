class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (const auto &c : s1) {
            ++map1[c];
        }
        int i = 0, j = 0;
        while (j < s2.size()) {
            while (j < s2.size() && j - i < s1.size()) {
                ++map2[s2[j++]];
            }
            if (map1 == map2) {
                return true;
            }
            if (--map2[s2[i]] == 0) {
                map2.erase(s2[i]);
            }
            ++i;
        }
        return false;
    }
};