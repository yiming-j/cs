class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        auto cmp = [] (const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq{cmp};
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            pq.push({i + days[i], apples[i]});
            while (!pq.empty() && (pq.top().first <= i || pq.top().second == 0)) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++ret;
                auto curr = pq.top();
                pq.pop();
                pq.push({curr.first, curr.second - 1});
            }
        }
        int j = n;
        while (!pq.empty()) {
            while (!pq.empty() && (pq.top().first <= j || pq.top().second == 0)) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++ret;
                auto curr = pq.top();
                pq.pop();
                pq.push({curr.first, curr.second - 1});
            }
            ++j;
        }
        return ret;
    }   
};