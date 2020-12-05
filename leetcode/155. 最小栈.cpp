class MinStack {
private:
    vector<int> s;
    vector<int> minS;
    vector<int> minCount;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        s.clear();
        minS.clear();
        minCount.clear();
    }
    
    void push(int x) {
        s.emplace_back(x);
        if (!minS.empty() && minS.back() <= x) {
            int count = minCount.back();
            minCount.pop_back();
            minCount.emplace_back(count + 1);
        } else {
            minS.emplace_back(x);
            minCount.emplace_back(1);
        }
    }
    
    void pop() {
        int x = s.back();
        s.pop_back();
        int count = minCount.back();
        minCount.pop_back();
        if (--count) {
            minCount.emplace_back(count);
        } else {
            minS.pop_back();
        }
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minS.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */