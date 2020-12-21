class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            ++count[c - 'a'];
        }
        for (char c : s) {
            if (count[c - 'a'] == 1) {
                return c;
            }
        }
        return ' ';
    }
};