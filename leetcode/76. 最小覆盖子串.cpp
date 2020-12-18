class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapS, mapT;
        for (char c : t) {
            ++mapT[c];
        }
        int l = 0, r = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            bool flag = false;
            while (j < s.size() && !flag) {
                ++mapS[s[j]];
                if (mapS.size() >= mapT.size() && mapT.count(s[j]) && mapS[s[j]] >= mapT[s[j]]) {
                    flag = true;
                    for (auto const kv : mapT) {
                        if (mapS[kv.first] < kv.second) {
                            flag = false;
                            break;
                        }
                    }
                }
                ++j;
            }
            while (flag) {
                if (r - l == 0 || r - l > j - i) {
                    l = i, r = j;
                }
                --mapS[s[i]];
                if (mapT.count(s[i]) && mapS[s[i]] < mapT[s[i]]) {
                    flag = false;
                }
                if (mapS[s[i]] == 0) {
                    mapS.erase(s[i]);
                }
                ++i;
            }
        }
        return s.substr(l, r - l);
    }
};