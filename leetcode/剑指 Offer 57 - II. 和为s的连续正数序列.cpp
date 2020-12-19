class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int i = 1, j = 1;
        int upper = target / 2 + 1;
        int sum = 0;
        while (j <= upper) {
            while (j <= upper && sum < target) {
                sum += j;
                ++j;
            }
            while (sum >= target) {
                if (sum == target) {
                    vector<int> temp(j - i, 0);
                    iota(temp.begin(), temp.end(), i);
                    ans.push_back(temp);
                }
                sum -= i;
                ++i;
            }
        }
        return ans;
    }
};