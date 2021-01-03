/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        unique_ptr<ListNode> dummy1(new ListNode());
        unique_ptr<ListNode> dummy2(new ListNode());
        ListNode* l1 = dummy1.get();
        ListNode* l2 = dummy2.get();
        for (auto node = head; node; node = node->next) {
            if (node->val < x) {
                l1->next = node;
                l1 = l1->next;
            } else {
                l2->next = node;
                l2 = l2->next;
            }
        }
        l2->next = nullptr;
        l1->next = dummy2->next;
        return dummy1->next;
    }
};