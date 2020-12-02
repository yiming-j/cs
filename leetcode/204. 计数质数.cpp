class Solution {
private:
    bool isPrime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                ++ans;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++ans;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};