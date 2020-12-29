class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> map;
        for (const int &num : nums) {
            ++map[num];
        }
        vector<pair<int, int>> count(map.begin(), map.end());
        sort(count.begin(), count.end());
        int n = count.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return count[0].first * count[0].second;
        }
        int first = count[0].first * count[0].second;
        int second = count[1].first == count[0].first + 1 ? max(first, count[1].first * count[1].second) : first + count[1].first * count[1].second;
        for (int i = 2; i < n; ++i) {
            int temp = second;
            second = count[i].first == count[i - 1].first + 1 ? max(second, first + count[i].first * count[i].second) : second + count[i].first * count[i].second;
            first = temp;
        }
        return second;
    }
};