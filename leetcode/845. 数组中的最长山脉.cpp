class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0;
        int size = A.size();
        int ans = 0;
        while (left + 2 < size) {
            int right = left + 1;
            if (A[left] < A[left + 1]) {
                while (right + 1 < size && A[right] < A[right + 1]) {
                    ++right;
                }
                if (right + 1 < size && A[right] > A[right + 1]) {
                    while (right + 1 < size && A[right] > A[right + 1]) {
                        ++right;
                    }
                    ans = max(ans, right - left + 1);
                } else {
                    ++right;
                }
            }
            left = right;
        }
        return ans;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = A.size();
        vector<int> left(size, 1);
        vector<int> right(size, 1);
        for (int i = 1; i < size; ++i) {
            if (A[i] - A[i - 1] > 0) {
                left[i] += left[i - 1];
            }
        }
        for (int i = size - 2; i >= 0; --i) {
            if (A[i] - A[i + 1] > 0) {
                right[i] += right[i + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (left[i] == 1 || right[i] == 1) {
                continue;
            }
            ans = max(ans, left[i] + right[i] - 1);
        }
        return ans;
    }
};