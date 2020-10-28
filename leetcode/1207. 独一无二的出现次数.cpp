class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for (const auto &num : arr) {
            ++map[num];
        }
        unordered_set<int> set;
        for (const auto &it : map) {
            if (set.count(it.second)) {
                return false;
            }
            set.insert(it.second);
        }
        return true;
    }
};