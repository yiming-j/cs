class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> map;
        int ret = 0;
        for (const auto &domino : dominoes) {
            pair<int, int> temp = domino[0] < domino[1] ? make_pair(domino[0], domino[1]) : make_pair(domino[1], domino[0]);
            if (map.count(temp)) {
                ret += map[temp];
            }
            ++map[temp];
        }
        return ret;
    }
};