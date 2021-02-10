class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto &building : buildings) {
            events.emplace_back(building[0], -building[2]);
            events.emplace_back(building[1], building[2]);
        }
        sort(events.begin(), events.end());
        multiset<int> heights;
        heights.insert(0);
        vector<vector<int>> ret;
        for (const auto &event : events) {
            if (event.second < 0) {
                if (-event.second > *heights.rbegin()) {
                    ret.push_back({event.first, -event.second});
                }
                heights.insert(-event.second);
            } else {
                heights.erase(heights.find(event.second));
                if (event.second > *heights.rbegin()) {
                    ret.push_back({event.first, *heights.rbegin()});
                }
            }
        }
        return ret;
    }
};