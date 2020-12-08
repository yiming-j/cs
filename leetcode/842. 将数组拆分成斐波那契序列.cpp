class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int n = S.size();
        for (int len1 = 1; 2 * len1 <= n && len1 <= 10; ++len1) {
            string s1 = S.substr(0, len1);
            long long n1 = stoll(s1);
            if (n1 != 0 && s1[0] == '0') {
                return {};
            }
            if (n1 >= INT_MAX) {
                return {};
            }
            for (int len2 = 1; 2 * len2 <= n && len2 <= 10; ++len2) {
                string s2 = S.substr(len1, len2);
                long long n2 = stoll(s2);
                if (n2 >= INT_MAX || (n2 != 0 && s2[0] == '0')) {
                    continue;
                }
                ans.push_back(n1);
                ans.push_back(n2);
                long long num1 = n1, num2 = n2;
                int start = len1 + len2;
                int len3 = max(len1, len2);
                while (start + len3 <= n) {
                    string s3 = S.substr(start, len3);
                    long long num3 = stoll(s3);
                    if (num3 >= INT_MAX || (num3 != 0 && s3[0] == '0')) {
                        break;
                    }
                    if (num1 + num2 == num3) {
                        ans.push_back(num3);
                        start += len3;
                        num1 = num2;
                        num2 = num3;
                    } else if (start + len3 + 1 <= n) {
                        s3 = S.substr(start, len3 + 1);
                        long long num3 = stoll(s3);
                        if (num3 >= INT_MAX || (num3 != 0 && s3[0] == '0')) {
                            break;
                        }
                        if (num1 + num2 == num3) {
                            ans.push_back(num3);
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
                if (start == n) {
                    if (ans.size() < 3) {
                        return {};
                    }
                    return ans;
                }
                ans.clear();
            }
        }
        return {};
    }
};