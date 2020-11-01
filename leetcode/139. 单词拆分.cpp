class Solution {
private:
    unordered_set<string> set;
    unordered_map<string, bool> map;
    int max_length = 0;
    
    bool dfs(string s) {
        if (set.count(s)) {
            return map[s] = true;
        }
        if (map.count(s)) {
            return map[s];
        }
        for (int i = 1; i <= max_length; ++i) {
            if (set.count(s.substr(0, i))) {
                if (dfs(s.substr(i))) {
                    return map[s] = true;
                }
            }
        }
        return map[s] = false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const auto &word : wordDict) {
            set.insert(word);
            max_length = max(max_length, (int)word.size());
        }
        return dfs(s);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (const auto &word : wordDict) {
            set.insert(word);
        }
        int size = s.size();
        vector<bool> dp(size + 1);
        dp[0] = true;
        for (int i = 1; i <= size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};