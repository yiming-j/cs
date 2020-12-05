class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        for (const int &num : nums) {
            if (!map.count(num - 1)) {
                map[num].push(1);
            } else {
                int len = map[num - 1].top();
                map[num - 1].pop();
                if (map[num - 1].empty()) {
                    map.erase(num - 1);
                }
                map[num].push(len + 1);
            }
        }
        for (const auto &it : map) {
            if (it.second.top() < 3) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        for (const int &num : nums) {
            ++count[num];
        }
        for (const int &num : nums) {
            if (count[num] == 0) {
                continue;
            }
            if (end[num - 1]) {
                --end[num - 1];
                ++end[num];
                --count[num];
            } else {
                if (count[num + 1] && count[num + 2]) {
                    --count[num];
                    --count[num + 1];
                    --count[num + 2];
                    ++end[num + 2];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};