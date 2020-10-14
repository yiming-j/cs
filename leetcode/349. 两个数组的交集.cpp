class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> ans;
        for (const auto &num: nums2) {
            if (!set.count(num)) {
                continue;
            }
            set.erase(num);
            ans.push_back(num);
        }
        return ans;
    }
};