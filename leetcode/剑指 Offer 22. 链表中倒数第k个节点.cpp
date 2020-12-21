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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < k; ++i) {
            p1 = p1->next;
        }
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};