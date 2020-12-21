class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;
    deque<int> count;
public:
    MaxQueue() {
        while (!q.empty()) {
            q.pop();
        }
        while (!dq.empty()) {
            dq.pop_front();
        }
        while (!count.empty()) {
            count.pop_front();
        }
    }
    
    int max_value() {
        if (q.empty()) {
            return -1;
        }
        return dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        int c = 1;
        while (!dq.empty() && value >= dq.back()) {
            c += count.back();
            dq.pop_back();
            count.pop_back();
        }
        dq.push_back(value);
        count.push_back(c);
        return;
    }
    
    int pop_front() {
        if (q.empty()) {
            return -1;
        }
        int ret = q.front();
        q.pop();
        int c = count.front();
        count.pop_front();
        --c;
        if (c == 0) {
            dq.pop_front();
        } else {
            count.push_front(c);
        }
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */