class Solution {
private:
    unordered_set<string> set;
    unordered_map<string, vector<string>> map;
    int max_length = 0;
    
    vector<string> dfs(string s) {
        if (map.count(s)) {
            return map[s];
        }
        vector<string> curr;
        int length = min((int)s.size(), max_length);
        for (int i = 1; i <= length; ++i) {
            string left = s.substr(0, i);
            if (!set.count(left)) {
                continue;
            }
            string right = s.substr(i);
            if (right.size() == 0) {
                curr.push_back(left);
                continue;
            }
            vector<string> rights = dfs(right);
            for (const auto &right : rights) {
                curr.push_back(left + ' ' + right);
            }
        }
        return map[s] = curr;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (const auto &word : wordDict) {
            set.insert(word);
            max_length = max(max_length, (int)word.size());
        }
        return dfs(s);
    }
};