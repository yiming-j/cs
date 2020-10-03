class Solution {
public:
    int paintingPlan(int n, int k) {
        if (n == 1 || k == 0) {
            return 1;
        }
        if (k < n) {
            return 0;
        }
        if (k == n * n) {
            return 1;
        }
        int result = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (n * (i + j) - (i * j) == k) {
                    result += combination(n, i) * combination(n, j);
                }
            }
        }
        return result;
    }
    
    int combination(int n, int i) {
        int nume = 1, deno = 1;
        while (i > 0) {
            nume *= n--;
            deno *= i--;
        }
        return nume / deno;
    }
};