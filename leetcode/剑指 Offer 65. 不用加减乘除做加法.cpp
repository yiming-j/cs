class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int temp = a ^ b;
            b = ((unsigned) a & b) << 1;
            a = temp;
        }
        return a;
    }
};