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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f = head, *s = head;
        for (int i = 0; i < k; ++i) {
            f = f->next;
        }
        while (f) {
            f = f->next;
            s = s->next;
        }
        ListNode* curr = head;
        for (int i = 0; i < k - 1; ++i) {
            curr = curr->next;
        }
        swap(s->val, curr->val);
        return head;
    }
};