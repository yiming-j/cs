class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] - arr[j] < arr[j] && map.find(arr[i] - arr[j]) != map.end()) {
                    dp[i][j] = dp[j][map[arr[i] - arr[j]]] + 1;
                    ret = max(ret, dp[i][j]);
                }
            } 
        }
        return ret > 0 ? ret + 2 : 0;
    }
};