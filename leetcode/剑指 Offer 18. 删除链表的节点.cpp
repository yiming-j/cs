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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummy = ListNode(0);
        ListNode* curr = head;
        ListNode* prev = &dummy;
        prev->next = curr;
        while (curr && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            prev->next = curr->next;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }
        head->next = deleteNode(head->next, val);
        return head;
    }
};