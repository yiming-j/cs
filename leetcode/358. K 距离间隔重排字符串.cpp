class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) {
            return s;
        }
        vector<int> count(26, 0);
        for (const char &c : s) {
            ++count[c - 'a'];
        }
        auto cmp = [&](const char &a, const char &b) {
            return count[a - 'a'] == count[b - 'a'] ? a > b : count[a - 'a'] < count[b - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c - 'a']) {
                pq.push(c);
            }
        }
        string ans = "";
        while (!pq.empty()) {
            vector<char> temp;
            int i = 0;
            while (i < k && !pq.empty()) {
                ans += pq.top();
                if (--count[pq.top() - 'a']) {
                    temp.push_back(pq.top());
                }
                pq.pop();
                ++i;
            }
            if (i < k && !temp.empty()) {
                return "";
            }
            for (const char &c : temp) {
                pq.push(c);
            }
        }
        return ans;
    }
};