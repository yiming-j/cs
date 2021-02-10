class Solution {
private:
    int subarraysWithAtMostK(vector<int>& A, int k) {
        int i = 0, j = 0;
        int ret = 0;
        unordered_map<int, int> map;
        while (j < A.size()) {
            ++map[A[j]];
            ++j;
            while (map.size() > k) {
                if (--map[A[i]] == 0) {
                    map.erase(A[i]);
                }
                ++i;
            }
            ret += j - i;
        }
        return ret;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarraysWithAtMostK(A, K) - subarraysWithAtMostK(A, K - 1); 
    }
};