class Solution {
private:
    int LIS(vector<int> &temp) {
        vector<int> dp;
        for (const int &t : temp) {
            auto it = lower_bound(dp.begin(), dp.end(), t);
            if (it == dp.end()) {
                dp.push_back(t);
            } else {
                *it = t;
            }
        }
        return dp.size();
    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> map;
        for (int i = 0; i < target.size(); ++i) {
            map[target[i]] = i;
        }
        vector<int> temp;
        for (const int &a : arr) {
            if (map.find(a) == map.end()) {
                continue;
            }
            temp.push_back(map[a]);
        }
        return target.size() - LIS(temp);
    }
};