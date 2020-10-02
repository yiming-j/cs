class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int dp_0 = leaves[0] == 'y', dp_1 = INT_MAX, dp_2 = INT_MAX - 1; //avoid overflow
        for(int i = 1; i < n; ++i) {
            int is_yellow = leaves[i] == 'y';
            int is_red = leaves[i] == 'r';
            dp_2 = min(dp_1, dp_2) + is_yellow;
            dp_1 = min(dp_0, dp_1) + is_red;
            dp_0 = dp_0 + is_yellow;
        }
        return dp_2;
    }
};