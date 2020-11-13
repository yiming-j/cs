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
private:
    ListNode* oddEvenList(ListNode* odd, ListNode* even_ori) {
        if (odd->next == nullptr) {
            odd->next = even_ori;
            return odd;
        }
        ListNode* even = odd->next;
        ListNode* odd_succ = even->next;
        if (odd_succ == nullptr) {
            odd->next = even_ori;
            return odd;
        }
        even->next = odd_succ->next;
        odd->next = oddEvenList(odd_succ, even_ori);
        return odd;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return oddEvenList(head, head->next);
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};