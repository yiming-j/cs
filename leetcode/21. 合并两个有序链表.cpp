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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1) {
            head->next = l1;
        }
        if (l2) {
            head->next = l2;
        }
        return dummy->next;
    }
};