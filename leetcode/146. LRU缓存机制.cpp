struct LRUNode {
    int key;
    int val;
    LRUNode* next;
    LRUNode() : key(0), val(0), next(nullptr) {}
    LRUNode(int k, int v) : key(k), val(v), next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, LRUNode*> cache;
    int _capacity;
    int _size;
    LRUNode* head;
    LRUNode* tail;
    
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        head = new LRUNode();
        tail = head;
    }
    
    void move(int key) {
        if (cache[key]->next == tail) {
            return;
        }
        LRUNode* pred = cache[key];
        LRUNode* curr = pred->next;
        LRUNode* succ = curr->next;
        cache[key] = tail;
        cache[succ->key] = pred;
        pred->next = succ;
        curr->next = nullptr;
        tail->next = curr;
        tail = tail->next;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        move(key);
        return cache[key]->next->val;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            tail->val = value;
            return;
        }
        tail->next = new LRUNode(key, value);
        cache[key] = tail;
        tail = tail->next;
        if (++_size > _capacity) {
            cache.erase(head->next->key);
            head = head->next;
            --_size;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */