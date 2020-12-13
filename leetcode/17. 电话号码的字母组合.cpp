class Solution {
private:
    unordered_map<char, vector<char>> map{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    
    vector<string> ans;
    
    void dfs(string digits, int i, int n, string temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        for (const char &c : map[digits[i]]) {
            temp.push_back(c);
            dfs(digits, i + 1, n, temp);
            temp.pop_back();
        }
    }
        
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) {
            return {};
        }
        dfs(digits, 0, n, "");
        return ans;
    }
};