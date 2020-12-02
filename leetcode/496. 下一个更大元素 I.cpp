class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        for (const int &num : nums2) {
            while (!s.empty() && s.top() < num) {
                map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while (!s.empty()) {
            map[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for (const int &num : nums1) {
            ans.emplace_back(map[num]);
        }
        return ans;
    }
};