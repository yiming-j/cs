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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        int len = 0;
        for (ListNode* node = head; node; node = node->next, ++len) {}
        k %= len;
        if (k == 0) {
            return head;
        }
        ListNode *f = head, *s = head;
        for (int i = 0; i < k; ++i) {
            f = f->next;
        }
        while (f->next) {
            f = f->next;
            s = s->next;
        }
        ListNode* ret = s->next;
        s->next = nullptr;
        f->next = head;
        return ret;
    }
};