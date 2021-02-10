class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> map;
        int i = 0, j = 0;
        int ret = 0;
        while (j < tree.size()) {
            while (j < tree.size() && (map.size() < 2 || (map.size() == 2 && map.count(tree[j])))) {
                ++map[tree[j++]];
            }
            ret = max(ret, j - i);
            while (map.size() >= 2) {
                if (--map[tree[i]] == 0) {
                    map.erase(tree[i]);
                }
                ++i;
            }
        }
        return ret;
    }
};