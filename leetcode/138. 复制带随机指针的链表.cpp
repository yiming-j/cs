/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* dummy1 = new Node(0);
        Node* dummy2 = new Node(0);
        dummy1->next = head;
        Node* curr = dummy2;
        while (dummy1) {
            if (dummy1->next) {
                if (map.count(dummy1->next)) {
                    curr->next = map[dummy1->next];
                } else {
                    curr->next = new Node(dummy1->next->val);
                    map[dummy1->next] = curr->next;
                }                
            }
            if (dummy1->random) {
                if (map.count(dummy1->random)) {
                    curr->random = map[dummy1->random];
                } else {
                    curr->random = new Node(dummy1->random->val);
                    map[dummy1->random] = curr->random;
                }                
            }
            curr = curr->next;
            dummy1 = dummy1->next;
        }
        return dummy2->next;
    }
};