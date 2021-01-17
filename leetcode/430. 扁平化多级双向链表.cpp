/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (head->child) {
            Node* succ = head->next;
            head->next = flatten(head->child);
            head->child->prev = head;
            Node* node = head->child;
            while (node->next) {
                node = node->next;
            }
            head->child = nullptr;
            if (succ) {
                succ->prev = node;                
            }
            node->next = flatten(succ);
        } else {
            head->next = flatten(head->next);
        }
        return head;
    }
};