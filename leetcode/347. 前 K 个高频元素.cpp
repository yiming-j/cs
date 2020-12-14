class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (const int& num: nums) {
            ++map[num];
        }
        auto cmp = [&](const int& a, const int& b) {
            return map[a] > map[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq{cmp};
        for (const auto& it : map) {
            pq.push(it.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

class Solution {
private:
    void quickPartition(vector<pair<int, int>> &pairs, int k, int lo, int hi) {
        if (hi == k - 1) {
            return;
        }
        int pivot = pairs[lo + (hi - lo) / 2].second;
        int left = lo, right = hi;
        while (left <= right) {
            while (left <= right && pairs[left].second > pivot) {
                ++left;
            }
            while (left <= right && pairs[right].second < pivot) {
                --right;
            }
            if (left <= right) {
                swap(pairs[left], pairs[right]);
                ++left;
                --right;
            }
        }
        if (right > k - 1) {
            quickPartition(pairs, k, lo, right);
        } else if (right < k - 1) {
            quickPartition(pairs, k, left, hi);
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (const int& num: nums) {
            ++map[num];
        }
        vector<pair<int, int>> pairs;
        for (const auto& it : map) {
            pairs.push_back({it.first, it.second});
        }
        quickPartition(pairs, k, 0, pairs.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pairs[i].first);
        }
        return ans;
    }
};