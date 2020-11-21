class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumGas = 0;
            int sumCost = 0;
            int j = 0;
            for (; j < n; ++j) {
                int idx = (i + j) % n;
                sumGas += gas[idx];
                sumCost += cost[idx];
                if (sumGas < sumCost) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
            i += j + 1;
        }
        return -1;
    }
};