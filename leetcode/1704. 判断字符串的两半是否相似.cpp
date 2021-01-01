class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.size() / 2; ++i) {
            char c = tolower(s[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++count1;
            }
        }
        for (int j = s.size() / 2; j < s.size(); ++j) {
            char c = tolower(s[j]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++count2;
            }            
        }
        return count1 == count2;
    }
};