class Solution {
private:
    int bit_count(int num) {
        int ans = 0;
        while (num) {
            ans += num & 0x1;
            num >>= 1;
        }
        return ans;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bits(10001, 0);
        for (const auto &num : arr) {
            bits[num] = bit_count(num);
        }
        sort(arr.begin(), arr.end(), 
             [&](const int &a, const int &b) {
                 return bits[a] == bits[b] ? a < b : bits[a] < bits[b];
             });
        return arr;
    }
};