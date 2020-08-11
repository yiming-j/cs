class Solution {
public:
    string replaceSpace(string s) {
        int i = 0;
        int size = s.size();
        while (i < size) {
            if (s[i] == ' ') {
                s += "  ";
            }
            i++;
        }
        i--;
        int j = s.size() - 1;
        while (j > i) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
            i--;
        }
        return s;
    }
};