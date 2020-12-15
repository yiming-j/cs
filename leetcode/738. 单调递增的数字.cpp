class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string ans = "";
        string s = to_string(N);
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (ans.empty() || s[i] >= ans.back()) {
                ans.push_back(s[i]);
                ++i;
            } else {
                int count9 = 1;
                char c = ans.back();
                ans.pop_back();
                while (!ans.empty()) {
                    if (--c >= ans.back()) {
                        ans.push_back(c);
                        break;
                    } 
                    c = ans.back();
                    ans.pop_back();
                    ++count9;
                }
                if (ans.empty()) {
                    ans += (c - 1);
                }
                ans += string(count9, '9');
                ++i;
                break;
            }
        }
        while (i < n) {
            ans.push_back('9');
            ++i;
        }
        return stoi(ans);
    }
};

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        while (i < strN.size()) {
            if (strN[i] < strN[i - 1]) {
                break;
            }
            ++i;
        }
        if (i < strN.size()) {
            while (i > 0 && strN[i - 1] > strN[i]) {
                --strN[i - 1];
                --i;
            }
            ++i;
            while (i < strN.size()) {
                strN[i] = '9';
                ++i;
            }
        }
        return stoi(strN);
    }
};