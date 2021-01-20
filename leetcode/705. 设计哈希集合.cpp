class MyHashSet {
private:
    vector<list<int>> set;
    int size = 1e3 + 7;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        set = vector<list<int>>(size);
    }
    
    void add(int key) {
        int k = key % size;
        if (find(set[k].begin(), set[k].end(), key) == set[k].end()) {
            set[k].insert(set[k].begin(), key);
        }
    }
    
    void remove(int key) {
        int k = key % size;
        if (find(set[k].begin(), set[k].end(), key) != set[k].end()) {
            set[k].remove(key);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key % size;
        return find(set[k].begin(), set[k].end(), key) != set[k].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */