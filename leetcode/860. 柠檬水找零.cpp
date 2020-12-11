class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0;
        for (const int &bill : bills) {
            if (bill == 5) {
                ++f;
            } else if (bill == 10) {
                if (f == 0) {
                    return false;
                }
                ++t;
                --f;
            } else {
                if (t > 0 && f > 0) {
                    --t; 
                    --f;
                } else if (f >= 3) {
                    f -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};