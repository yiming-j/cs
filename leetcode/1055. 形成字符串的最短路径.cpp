class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> pos(26, vector<int>());
        for (int i = 0; i < source.size(); ++i) {
            pos[source[i] - 'a'].push_back(i);
        }
        if (pos[target[0] - 'a'].empty()) {
            return -1;
        }
        int last = pos[target[0] - 'a'].front();
        int ret = 1;
        for (int i = 1; i < target.size(); ++i) {
            if (pos[target[i] - 'a'].empty()) {
                return -1;
            }
            auto it = upper_bound(pos[target[i] - 'a'].begin(), pos[target[i] - 'a'].end(), last);
            if (it == pos[target[i] - 'a'].end()) {
                ++ret;
                last = pos[target[i] - 'a'].front();
            } else {
                last = *it;
            }
        }
        return ret;
    }
};