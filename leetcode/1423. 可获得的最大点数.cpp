class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ret = INT_MAX, curr = 0;
        int n = cardPoints.size();
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && j - i < n - k) {
                curr += cardPoints[j++];
            }
            ret = min(ret, curr);
            curr -= cardPoints[i++];
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), -ret);
    }
};