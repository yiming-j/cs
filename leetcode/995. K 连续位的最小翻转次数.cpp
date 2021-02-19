class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> q;
        int ret = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (!q.empty() && q.front() + K <= i) {
                q.pop();
            }
            if (q.size() % 2 != A[i]) {
                continue;
            }
            if (i + K > A.size()) {
                return -1;
            }
            q.push(i);
            ++ret;
        }
        return ret;
    }
};