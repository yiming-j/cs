class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size = scores.size();
        vector<vector<int>> age_score(size, vector<int>(2));
        for (int i = 0; i < size; ++i) {
            age_score[i][0] = ages[i];
            age_score[i][1] = scores[i];
        }
        sort(age_score.begin(), age_score.end());
        vector<int> dp(size, 0);
        dp[0] = age_score[0][1];
        int team_score = age_score[0][1];
        for (int i = 1; i < size; ++i) {
            dp[i] = age_score[i][1];
            for (int j = i - 1; j >= 0; --j) {
                if (age_score[i][1] >= age_score[j][1]) {
                    dp[i] = max(dp[i], dp[j] + age_score[i][1]);
                }
            }
            team_score = max(team_score, dp[i]);
        }
        return team_score;
    }
};