class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for (const auto c : s) {
            switch(c) {
                case 'A':
                    x = 2 * x + y;
                    break;
                case 'B':
                    y = 2 * y + x;
                    break;
            }
        }
        return x + y;
    }
};