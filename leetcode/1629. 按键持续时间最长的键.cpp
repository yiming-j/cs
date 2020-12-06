class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int size = releaseTimes.size();
        int pred = 0;
        int ans_time = 0;
        char ans = 'a' - 1;
        for (int i = 0; i < size; ++i) {
            int t = releaseTimes[i] - pred;
            pred = releaseTimes[i];
            if (t > ans_time || (t == ans_time && keysPressed[i] > ans)) {
                ans = keysPressed[i];
                ans_time = t;
            }
        }
        return ans;
    }
};