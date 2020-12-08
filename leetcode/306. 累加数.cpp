class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int len1 = 1; 2 * len1 <= n && len1 <= 19; ++len1) {
            string s1 = num.substr(0, len1);
            long long n1 = stoll(s1);
            if (n1 != 0 && s1[0] == '0') {
                return false;
            }
            for (int len2 = 1; 2 * len2 <= n && len2 <= 19; ++len2) {
                string s2 = num.substr(len1, len2);
                long long n2 = stoll(s2);
                if (n2 != 0 && s2[0] == '0') {
                    continue;
                }
                long long num1 = n1, num2 = n2;
                int start = len1 + len2;
                int len3 = max(len1, len2);
                bool flag = false;
                while (start + len3 <= n) {
                    string s3 = num.substr(start, len3);
                    long long num3 = stoll(s3);
                    if (num3 != 0 && s3[0] == '0') {
                        break;
                    }
                    if (num1 + num2 == num3) {
                        flag = true;
                        start += len3;
                        num1 = num2;
                        num2 = num3;
                    } else if (start + len3 + 1 <= n) {
                        s3 = num.substr(start, len3 + 1);
                        long long num3 = stoll(s3);
                        if (num3 != 0 && s3[0] == '0') {
                            break;
                        }
                        if (num1 + num2 == num3) {
                            flag = true;
                            start += len3 + 1;
                            len3 += 1;
                            num1 = num2;
                            num2 = num3;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if (start == n && flag) {
                    return true;
                }
            }
        }
        return false;
    }
};