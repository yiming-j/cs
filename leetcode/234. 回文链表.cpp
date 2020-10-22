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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* pre = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        if (fast) {
            slow = slow->next;
        }
        
        while (pre && slow) {
            if (pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};