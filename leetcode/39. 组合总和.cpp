class Solution {
private:
    vector<vector<int>> ret;
    
    void dfs(vector<int>& candidates, int target, vector<int>& temp, int start) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], temp, i);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, target, temp, 0);
        return ret;
    }
};