class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mi = (n + 1) / 2;
        vector<int> temp1(nums.begin(), nums.begin() + mi);
        vector<int> temp2(nums.begin() + mi, nums.end());
        int i = temp1.size() - 1, j = temp2.size() - 1;
        int k = 0;
        while (i >= 0 && j >= 0) {
            nums[k++] = temp1[i--];
            nums[k++] = temp2[j--];
        }
        if (i >= 0) {
            nums[k++] = temp1[i--];
        }
    }
};

    