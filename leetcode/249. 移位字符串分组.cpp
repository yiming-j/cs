class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        for (const auto &s : strings) {
            string temp = s;
            int delta = temp[0] - 'a';
            for (auto &c : temp) {
                c -= delta;
                if (c < 'a') {
                    c += 26;
                }
            }
            map[temp].push_back(s);
        }
        vector<vector<string>> ret;
        for (const auto &kv : map) {
            ret.push_back(kv.second);
        }
        return ret;
    }
};