class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> temp(n1 + n2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                temp[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < n1 + n2 - 1; ++i) {
            temp[i + 1] += temp[i] / 10;
            temp[i] %= 10;
        }
        while (!temp.empty() && temp.back() == 0) {
            temp.pop_back();
        }
        string ret;
        for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            ret += to_string(*it);
        }
        return ret.empty() ? "0" : ret;
    }
};