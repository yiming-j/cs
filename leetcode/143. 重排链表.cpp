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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode* pred = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* succ = curr->next;
            curr->next = pred;
            pred = curr;
            curr = succ;
        }
        return pred;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        } 
        ListNode* l1 = head;
        ListNode* mid = findMid(head);
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        while (l2) {
            ListNode* succ_1 = l1->next;
            ListNode* succ_2 = l2->next;
            l1->next = l2;
            l2->next = succ_1;
            l1 = succ_1;
            l2 = succ_2;
        }
    }
};