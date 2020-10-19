class Solution {
public:
    string build(string str) {
        string new_str;
        for (const char &c : str) {
            if (isalpha(c)) {
                new_str.push_back(c);
            } else if (!new_str.empty()) {
                new_str.pop_back();
            }
        }
        return new_str;
    }
    
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int skip_S = 0, skip_T = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || skip_S > 0)) {
                if (S[i] == '#') {
                    ++skip_S;
                } else {
                    --skip_S;
                }
                --i;
            }
            while (j >= 0 && (T[j] == '#' || skip_T > 0)) {
                if (T[j] == '#') {
                    ++skip_T;
                } else {
                    --skip_T;
                }
                --j;
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};