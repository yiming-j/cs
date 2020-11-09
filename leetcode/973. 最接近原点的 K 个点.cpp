class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int> &b) {
           return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; 
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<pair<int, int>> toSort(n);
        for (int i = 0; i < n; ++i) {
            toSort[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        }
        sort(toSort.begin(), toSort.end());
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; ++i) {
            ans[i] = points[toSort[i].second];
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<pair<int, int>> toSort(n);
        for (int i = 0; i < n; ++i) {
            toSort[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(toSort[i]);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; ++i) {
            ans[i] = points[pq.top().second];
            pq.pop();
        }
        return ans;
    }
};

class Solution {
private:
    void quickSelect(vector<pair<int, int>> &toSort, int lo, int hi, int K) {
        if (hi == K - 1) {
            return;
        }
        int pivot = toSort[lo + (hi - lo) / 2].first;
        int left = lo, right = hi;
        while (left <= right) {
            while (left <= right && toSort[left].first < pivot) {
                ++left;
            }
            while (left <= right && toSort[right].first > pivot) {
                --right;
            }
            if (left <= right) {
                swap(toSort[left], toSort[right]);
                ++left;
                --right;
            }
        }
        if (K - 1 <= right) {
            quickSelect(toSort, lo, right, K);
        } else if (K - 1 >= left) {
            quickSelect(toSort, left, hi, K);
        } 
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<pair<int, int>> toSort(n);
        for (int i = 0; i < n; ++i) {
            toSort[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        }
        quickSelect(toSort, 0, n - 1, K);
        vector<vector<int>> ans(K);
        for (int i = 0; i < K; ++i) {
            ans[i] = points[toSort[i].second];
        }
        return ans;
    }
};