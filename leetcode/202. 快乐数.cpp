class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        unordered_set<int> set;
        set.insert(n);
        while (n != 1) {
            int next = 0;
            while (n) {
                int rem = n % 10;
                next += rem * rem;
                n /= 10;
            }
            if (set.count(next)) {
                return false;
            }
            n = next;
            set.insert(n);
        }
        return true;
    }
};