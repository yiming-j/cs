class Solution {
private:
    vector<int> maxSub(vector<int> &nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (!ans.empty() && n - i + ans.size() > k && ans.back() < nums[i]) {
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        while (ans.size() > k) {
            ans.pop_back();
        }
        return ans;
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n1 + n2);
        int p1 = 0, p2 = 0, p = 0;
        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] > nums2[p2]) {
                ans[p++] = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                ans[p++] = nums2[p2++];
            } else {
                int i = p1, j = p2;
                for (; i < n1 && j < n2; ++i, ++j) {
                    if (nums1[i] > nums2[j]) {
                        ans[p++] = nums1[p1++];
                        break;
                    } else if (nums1[i] < nums2[j]) {
                        ans[p++] = nums2[p2++];
                        break;
                    }
                }
                if (i == n1 || j == n2) {
                    if (n1 - i > n2 - j) {
                        ans[p++] = nums1[p1++];
                    } else {
                        ans[p++] = nums2[p2++];
                    }
                }
            }
        }
        while (p1 < n1) {
            ans[p++] = nums1[p1++];
        }
        while (p2 < n2) {
            ans[p++] = nums2[p2++];
        }
        return ans;
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k);
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            vector<int> s1 = maxSub(nums1, i);
            vector<int> s2 = maxSub(nums2, k - i);
            vector<int> s = merge(s1, s2);
            for (int j = 0; j < k; ++j) {
                if (s[j] < ans[j]) {
                    break;
                }
                if (s[j] > ans[j]) {
                    ans = s;
                    break;
                }
            }           
        }
        return ans;
    }
};