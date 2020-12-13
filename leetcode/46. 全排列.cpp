class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int>& temp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            temp.push_back(nums[i]);
            dfs(nums, n, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        visited.resize(n, false);
        vector<int> temp;
        dfs(nums, n, temp);
        return ans;
    }
};
