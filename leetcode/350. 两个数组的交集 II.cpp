class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map1;
        for (const auto &num: nums1) {
            ++map1[num];
        }
        vector<int> ans;
        for (const auto &num: nums2) {
            if (!map1.count(num)) {
                continue;
            }
            ans.push_back(num);
            if (--map1[num] == 0) {
                map1.erase(num);
            }
        }
        return ans;
    }
};