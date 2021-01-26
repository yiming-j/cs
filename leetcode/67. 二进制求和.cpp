class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ret;
        while (i >= 0 || j >= 0) {
            int numA = i >= 0 ? a[i--] - '0' : 0;
            int numB = j >= 0 ? b[j--] - '0' : 0;
            int sum = numA + numB + carry;
            carry = sum / 2;
            ret += sum % 2 + '0';
        }
        if (carry) {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};