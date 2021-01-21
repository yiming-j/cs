class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (const auto &c : s) {
            ++map[c];
        }
        auto cmp = [&map] (const char &lhs, const char &rhs) {
            return map[lhs] < map[rhs];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (const auto &kv : map) {
            pq.push(kv.first);
        }
        string ret;
        while (!pq.empty()) {
            ret.push_back(pq.top());
            if (--map[pq.top()] == 0) {
                pq.pop(); 
            }
        }
        return ret;
    }
};