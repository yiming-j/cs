class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> jewels(52, 0);
        for (const char c : J) {
            if (isupper(c)) {
                jewels[c - 'A' + 26] = 1;
            } else {
                jewels[c - 'a'] = 1;
            }
        }
        int num_jewels = 0;
        for (const char c : S) {
            if (isupper(c)) {
                num_jewels += jewels[c - 'A' + 26];
            } else {
                num_jewels += jewels[c - 'a'];
            }            
        }
        return num_jewels;
    }
};