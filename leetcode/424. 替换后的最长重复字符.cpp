class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0;
        int i = 0, j = 0;
        vector<int> count(26);
        int maxCount = 0;
        while (j < s.size()) {
            while (j < s.size()) {
                ++count[s[j] - 'A'];
                maxCount = max(maxCount, count[s[j] - 'A']);
                ++j;
                if (maxCount + k >= j - i) {
                    ret = max(ret, j - i);
                } else {
                    break;
                }
            }
            --count[s[i] - 'A'];
            ++i;
            maxCount = *max_element(count.begin(), count.end());
        }
        return ret;
    }
};