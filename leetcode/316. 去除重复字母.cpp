class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0), visited(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++count[s[i] - 'a'];
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            while (ans.size() > 0 && !visited[s[i] - 'a'] && s[i] < ans.back() && count[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            if (!visited[s[i] - 'a']) {
                visited[s[i] - 'a'] = 1;
                ans.push_back(s[i]);
            }
            --count[s[i] - 'a'];
        }
        return ans;
    }
};