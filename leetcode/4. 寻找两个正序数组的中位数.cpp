class Solution {
private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        if (l1 > r1) {
            return nums2[l2 + k - 1];
        }
        if (l2 > r2) {
            return nums1[l1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }
        int right1 = min(r1, l1 + k / 2 - 1);
        int right2 = min(r2, l2 + k / 2 - 1);
        if (nums1[right1] < nums2[right2]) {
            return findKth(nums1, nums2, right1 + 1, r1, l2, r2, k - (right1 - l1 + 1));
        }
        return findKth(nums1, nums2, l1, r1, right2 + 1, r2, k - (right2 - l2 + 1));
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, 0, m - 1, 0, n - 1, (m + n + 1) / 2) + findKth(nums1, nums2, 0, m - 1, 0, n - 1, (m + n + 2) / 2)) * 0.5;
    }
};