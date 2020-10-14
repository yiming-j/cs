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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pred = dummy;
        while (pred->next != nullptr && pred->next->next != nullptr) {
            ListNode* curr = pred->next;
            ListNode* succ = curr->next;
            pred->next = succ;
            curr->next = succ->next;
            succ->next = curr;
            pred = curr;
        }
        
        return dummy->next;
    }
};