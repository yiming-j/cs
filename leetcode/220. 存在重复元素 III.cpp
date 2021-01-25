class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = map.lower_bound((long long)nums[i] - t);
            auto it2 = map.upper_bound((long long)nums[i] + t);
            for (; it != it2; ++it) {
                if (i - it->second <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }
        return false;
    }
};