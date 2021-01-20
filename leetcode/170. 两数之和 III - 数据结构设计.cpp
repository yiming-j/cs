class TwoSum {
private:
    multiset<int> set;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        set.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        set.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (set.empty()) {
            return false;
        }
        auto begin = set.begin(), end = --set.end();
        while (begin != end) {
            int sum = *begin + *end;
            if (sum == value) {
                return true;
            }
            if (sum < value) {
                ++begin;
            } else {
                --end;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */