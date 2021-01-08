class Solution {
private:
    vector<vector<int>> ret;
    vector<int> visited;
    
    void dfs(vector<int>& candidates, int target, vector<int>& temp, int start) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                continue;
            }
            if (target - candidates[i] >= 0) {
                visited[i] = 1;
                temp.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], temp, i + 1);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        visited.resize(candidates.size());
        vector<int> temp;
        dfs(candidates, target, temp, 0);
        return ret;
    }
};