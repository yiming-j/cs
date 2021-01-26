class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int n1 = i >= 0 ? num1[i--] - '0' : 0;
            int n2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = n1 + n2 + carry;
            ret += (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry) {
            ret += carry + '0';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};