class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> pos(26, -1);
        int ans = -1;
        int size = s.size(); 
        for (int i = 0; i < size; ++i) {
            if (pos[s[i] - 'a'] == -1) {
                pos[s[i] - 'a'] = i;
            } else {
                ans = max(ans, (i - pos[s[i] - 'a'] - 1));
            }
        }
        return ans;
    } 
};