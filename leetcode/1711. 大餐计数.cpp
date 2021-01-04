class Solution {    
public:
    int countPairs(vector<int>& deliciousness) {
        int m = 1e9 + 7;
        unordered_map<int, long long> map;
        for (const auto &d : deliciousness) {
            ++map[d];
        }
        vector<long long> power2(32);
        power2[0] = 1;
        for (int i = 1; i < 32; ++i) {
            power2[i] = 2 * power2[i - 1];
        }
        long long ret = 0;
        for (auto it = map.begin(); it != map.end(); ++it) {
            for (int i = 0; i < 32; ++i) {
                if (map.find(power2[i] - it->first) == map.end() || map[power2[i] - it->first] == 0) {
                    continue;
                }
                if (it->first == power2[i] - it->first) {
                    ret = (ret + it->second * (it->second - 1) / 2) % m;
                } else {
                    ret = (ret + it->second * map[power2[i] - it->first]) % m; 
                }
            }
            map[it->first] = 0;
        }
        return ret;
    }
};