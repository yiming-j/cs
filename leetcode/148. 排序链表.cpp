/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* findMid(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        ListNode* prev;
        while (f && f->next) {
            prev = s;
            f = f->next->next;
            s = s->next;
        }
        prev->next = nullptr;
        return s;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        l2->next = merge(l1, l2->next);
        return l2;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mi = findMid(head);
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(mi);
        return merge(l1, l2);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        auto curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1? l1 : l2;
        return dummy.next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = prev->next;
        int length = 0;
        while (curr) {
            curr = curr->next;
            ++length;
        }
        for (int size = 1; size < length; size <<= 1) {
            prev = &dummy;
            curr = prev->next;
            while (curr) {
                int count = size;
                ListNode* f = curr;
                ListNode* s = curr;
                ListNode* prev_s = s;
                ListNode* prev_f = f;
                while (s && count) {
                    prev_s = s;
                    s = s->next;
                    if (f) {
                        prev_f = f->next;
                        f = f->next;
                    }
                    if (f) {
                        f = f->next;
                    }
                    --count;
                }
                prev_s->next = nullptr;
                if(prev_f) prev_f->next = nullptr;
                ListNode* next = f;
                prev->next = merge(curr, s);
                curr = next;
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }
        return dummy.next;
    }
};