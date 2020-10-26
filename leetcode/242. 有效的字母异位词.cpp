class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (const char &c : s) {
            ++count[c - 'a'];
        }
        for (const char &c : t) {
            --count[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};