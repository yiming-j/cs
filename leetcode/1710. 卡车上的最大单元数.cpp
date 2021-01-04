class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] > rhs[1];
        });
        int ret = 0;
        int i = 0, n = boxTypes.size();
        while (truckSize) {
            if (i < n) {
                int curr = min(truckSize, boxTypes[i][0]);
                ret += curr * boxTypes[i][1];
                ++i;
                truckSize -= curr;
            } else {
                break;
            }
        }
        return ret;
    }
};