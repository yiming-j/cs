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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return nullptr;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (fast != slow) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* first = head;
        while (first != slow) {
            first = first->next;
            slow = slow->next;
        }
        return first;
    }
};