class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for (const auto &c : S) {
            ++count[c - 'a'];
        }
        auto cmp = [&](const char &a, const char &b) {
            return count[a - 'a'] < count[b - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq{cmp};
        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c - 'a']) {
                pq.push(c);
            }
        }
        string ans = "";
        while (pq.size() >= 2) {
            char c1 = pq.top(); pq.pop();
            char c2 = pq.top(); pq.pop();
            ans += c1;
            ans += c2;
            if (--count[c1 - 'a']) {
                pq.push(c1);
            }
            if (--count[c2 - 'a']) {
                pq.push(c2);
            }
        }
        if (pq.size() == 1) {
            if (count[pq.top() - 'a'] > 1) {
                ans = "";
            } else {
                ans += pq.top();
            }
        }
        return ans;
    }
};