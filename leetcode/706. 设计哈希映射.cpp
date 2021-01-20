class MyHashMap {
private:
    vector<list<pair<int, int>>> map;
    int MOD = 1e4 + 7;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map = vector<list<pair<int, int>>>(MOD);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = key % MOD;
        auto it = map[k].begin();
        for (; it != map[k].end(); ++it) {
            if (it->first == key) {
                break;
            }
        }
        if (it == map[k].end()) {
            map[k].push_front({key, value});
        } else {
            *it = {key, value};
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = key % MOD;
        auto it = map[k].begin();
        for (; it != map[k].end(); ++it) {
            if (it->first == key) {
                break;
            }
        }
        if (it == map[k].end()) {
            return -1;
        }
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = key % MOD;
        auto it = map[k].begin();
        for (; it != map[k].end(); ++it) {
            if (it->first == key) {
                break;
            }
        }
        if (it == map[k].end()) {
            return;
        }
        map[k].remove({it->first, it->second});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */