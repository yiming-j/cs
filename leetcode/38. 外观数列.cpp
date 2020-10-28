class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            int size = s.size();
            string temp;
            for (int j = 0; j < size; ++j) {
                int count = 1;
                while (j < size && s[j] == s[j + 1]) {
                    ++count;
                    ++j;
                }
                temp += to_string(count) + s[j];
            }
            s = temp;
        }
        return s;
    }
};