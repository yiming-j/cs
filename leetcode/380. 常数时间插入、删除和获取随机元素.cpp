class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> map;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();
        map.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) {
            return false;
        }
        map[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map.count(val)) {
            return false;
        }
        int idx = map[val];
        map[nums.back()] = idx;
        nums[idx] = nums.back();
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */