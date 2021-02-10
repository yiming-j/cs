class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() <= 1) {
            return arr.size();
        }
        int i = 0;
        while (i < arr.size() - 1 && arr[i + 1] == arr[i]) {
            ++i;
        }
        int j = i + 1;
        int ret = j < arr.size() ? j - i + 1 : 1;
        while (j < arr.size() - 1) {
            int diff = arr[j] - arr[i];
            while (j < arr.size() - 1 && arr[j + 1] != arr[j] && ((arr[j + 1] - arr[j]) ^ diff) < 0) {
                diff = arr[j + 1] - arr[j];
                ++j;
            }
            ret = max(ret, j - i + 1);
            i = j;
            while (i < arr.size() - 1 && arr[i + 1] == arr[i]) {
                ++i;
            }
            j = i + 1;
        }
        return ret;
    }
};