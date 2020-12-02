class StockSpanner {
private:
    stack<int> s;
    unordered_map<int, int> map;
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int ans = 1;
        while (!s.empty() && s.top() <= price) {
            ans += map[s.top()];
            s.pop();
        }
        s.push(price);
        return map[price] = ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */