class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> s;
        for (int& num : nums) {
            s.push_back(to_string(num));
        }
        sort(s.begin(), s.end(), [](string s1, string s2) -> bool {
            return s1 + s2 < s2 + s1;
        });
        string ret;
        for (string& str : s) {
            ret += str;
        }
        return ret;
    }
};