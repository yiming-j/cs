class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> min_freq(26, INT_MAX);
        vector<int> freq(26, 0);
        for (const auto &word: A) {
            fill(freq.begin(), freq.end(), 0);
            for (const auto &c : word) {
                ++freq[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], freq[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < min_freq[i]; ++j) {
                ans.emplace_back(1, 'a' + i);
            }
        }
        return ans;
    }
};