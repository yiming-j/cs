class Solution {
private:
    vector<string> ans;
    
    void dfs(int l, int r, string& temp) {
        if (l == 0 && r == 0) {
            ans.push_back(temp);
            return;
        }
        if (l > 0) {
            temp.push_back('(');
            dfs(l - 1, r, temp);
            temp.pop_back();
        }
        if (l == r) {
            return;
        }
        if (r > 0) {
            temp.push_back(')');
            dfs(l, r - 1, temp);
            temp.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int l = n, r = n;
        string temp = "";
        dfs(l, n, temp);
        return ans;
    }
};