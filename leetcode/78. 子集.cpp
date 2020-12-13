class Solution {
private:
    vector<vector<int>> ans;
    
    void dfs(vector<int>& nums, int i, int n, vector<int>& temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        dfs(nums, i + 1, n, temp);
        temp.push_back(nums[i]);
        dfs(nums, i + 1, n, temp);
        temp.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        dfs(nums, 0, n, temp);
        return ans;
    }
};