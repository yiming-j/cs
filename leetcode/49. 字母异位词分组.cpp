class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto &str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (const auto &it : map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};