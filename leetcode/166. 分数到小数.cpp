class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long long, int> map;
        string ans = "";
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            ans += '-';
        }
        long long n = abs(numerator);
        long long d = abs(denominator);
        ans += to_string(n / d);
        n %= d;
        n *= 10;
        if (n == 0) {
            return ans;
        }
        ans += '.';
        while (n) {
            while (n < d && !map.count(n)) {
                map[n] = ans.size();
                n *= 10;
                ans += '0';
            }
            if (map.count(n)) {
                ans.insert(map[n], "(");
                ans += ')';
                return ans;
            }
            map[n] = ans.size();
            ans += to_string(n / d);
            n %= d;
            n *= 10;
        }
        return ans;
    }
};