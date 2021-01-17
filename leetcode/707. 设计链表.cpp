class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int v) : val(v), next(nullptr) {}
    };
    
    ListNode* dummy;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* node = dummy->next;
        while (index && node) {
            --index;
            node = node->next;
        }
        if (index || node == nullptr) {
            return -1;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* succ = dummy->next;
        dummy->next = new ListNode(val);
        dummy->next->next = succ;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* prev = dummy;
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* prev = dummy;
        while (index && prev) {
            --index;
            prev = prev->next;
        }
        if (prev == nullptr) {
            return;
        }
        ListNode* succ = prev->next;
        prev->next = new ListNode(val);
        prev->next->next = succ;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }
        ListNode* prev = dummy;
        while (index && prev) {
            --index;
            prev = prev->next;
        }
        if (prev == nullptr || prev->next == nullptr) {
            return;
        }
        prev->next = prev->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */