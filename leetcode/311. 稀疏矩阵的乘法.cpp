class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<int, unordered_map<int, int>> map1;
        unordered_map<int, unordered_map<int, int>> map2;
        int m1 = A.size(), n1 = A[0].size();
        int m2 = B.size(), n2 = B[0].size();
        for (int i = 0; i < m1; ++i) {
            for (int j = 0; j < n1; ++j) {
                if (A[i][j] == 0) {
                    continue;
                }
                map1[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < m2; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (B[i][j] == 0) {
                    continue;
                }
                map2[j][i] = B[i][j];
            }
        }
        vector<vector<int>> ret(m1, vector<int>(n2));
        for (int i = 0; i < m1; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (!map2.count(j)) {
                    continue;
                }
                for (const auto &kv : map1[i]) {
                    if (!map2[j].count(kv.first)) {
                        continue;
                    }
                    ret[i][j] += kv.second * map2[j][kv.first];
                }
            }
        }
        return ret;
    }
};