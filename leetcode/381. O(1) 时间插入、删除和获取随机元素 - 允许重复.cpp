class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> map;
    vector<int> nums;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = !map.count(val);
        map[val].insert(nums.size());
        nums.push_back(val);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!map.count(val)) {
            return false;
        }
        int idx = *(map[val].begin());
        nums[idx] = nums.back();
        map[val].erase(idx);
        if (map[val].empty()) {
            map.erase(val);
        }
        map[nums.back()].insert(idx);
        map[nums.back()].erase(nums.size() - 1);
        if (map[nums.back()].empty()) {
            map.erase(nums.back());
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */