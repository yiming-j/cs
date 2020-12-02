class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int i = 0;
        while (i < n - 1 && s[i] >= s[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return num;
        }
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] >= s[maxIdx]) {
                maxIdx = j;
            }
        }
        for (int i = 0; i < maxIdx; ++i) {
            if (s[i] < s[maxIdx]) {
                swap(s[i], s[maxIdx]);
                break;
            }
        }
        return stoi(s);
    }
};