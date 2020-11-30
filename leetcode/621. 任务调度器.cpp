class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const auto &c : tasks) {
            ++count[c - 'A'];
        }
        auto cmp = [&](const char &a, const char &b) {
            return count[a - 'A'] < count[b - 'A'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq{cmp};
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (count[c - 'A']) {
                pq.push(c);
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            int i = 0;
            vector<char> temp;
            while (i <= n && !pq.empty()) {
                ++ans;
                if (--count[pq.top() - 'A']) {
                    temp.push_back(pq.top());
                }
                pq.pop();
                ++i;
            }
            if (i <= n && !temp.empty()) {
                ans += n - i + 1;
            }
            for (const char &c : temp) {
                pq.push(c);
            }
        }
        return ans;
    }
};