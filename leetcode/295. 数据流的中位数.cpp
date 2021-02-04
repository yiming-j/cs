class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> minpq;
    priority_queue<int, vector<int>, greater<int>> maxpq;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        while (!minpq.empty()) {
            minpq.pop();
        }
        while (!maxpq.empty()) {
            maxpq.pop();
        }
    }
    
    void addNum(int num) {
        if (minpq.empty() || num <= minpq.top()) {
            minpq.push(num);
        } else {
            maxpq.push(num);
        }
        while (minpq.size() < maxpq.size()) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        while (minpq.size() > maxpq.size() + 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if ((minpq.size() + maxpq.size()) % 2 == 0) {
            return (double(minpq.top()) + maxpq.top()) / 2;
        }
        return minpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */