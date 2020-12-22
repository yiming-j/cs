class Solution {
private:
    vector<bool> visited;
    vector<string> ret;
    void dfs(string &s, string &temp) {
        if (temp.size() == s.size()) {
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i] || (i > 0 && s[i] == s[i - 1] && !visited[i - 1])) {
                continue;
            }
            temp.push_back(s[i]);
            visited[i] = true;
            dfs(s, temp);
            visited[i] = false;
            temp.pop_back();
        }
    }
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        visited.resize(s.size(), false);
        string temp;
        dfs(s, temp);
        return ret;
    }
};