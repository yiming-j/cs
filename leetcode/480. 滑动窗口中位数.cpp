class DualHeap {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    int k;
    int smallSize, largeSize;
    unordered_map<int, int> delayed;
    
public:
    DualHeap(int k) : k(k), smallSize(0), largeSize(0) {}
    
private:
    template<typename T>
    void prune(T& heap) {
        while (!delayed.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                if (--delayed[num] == 0) {
                    delayed.erase(num);
                }
                heap.pop();
            } else {
                break;
            }
        }
    }
    
    void makeBalance() {
        if (smallSize > largeSize + 1) {
            --smallSize;
            ++largeSize;
            large.push(small.top());
            small.pop();
        }
        if (smallSize < largeSize) {
            ++smallSize;
            --largeSize;
            small.push(large.top());
            large.pop();
        }
        prune(small);
        prune(large);
    }

public:
    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }
    
    void erase(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
        } else {
            --largeSize;
        }
        makeBalance();
    }
    
    double getMedian() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualHeap dualHeap(k);
        for (int i = 0; i < k; ++i) {
            dualHeap.insert(nums[i]);
        }
        vector<double> ret;
        ret.push_back(dualHeap.getMedian());
        for (int i = k; i < nums.size(); ++i) {
            dualHeap.insert(nums[i]);
            dualHeap.erase(nums[i - k]);
            ret.push_back(dualHeap.getMedian());
        }
        return ret;
    }
};