class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mapP;
        unordered_map<char, int> mapS;
        for (const char &c : p) {
            ++mapP[c];
        }
        int i = 0, j = 0;
        vector<int> ret;
        while (j < s.size()) {
            while (j - i < p.size()) {
                ++mapS[s[j]];
                ++j;
            }
            if (mapS == mapP) {
                ret.push_back(i);
            }
            if (--mapS[s[i]] == 0) {
                mapS.erase(s[i]);
            }
            ++i;
        }
        return ret;
    }
};