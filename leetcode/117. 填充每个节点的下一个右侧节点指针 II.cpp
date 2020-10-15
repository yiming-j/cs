/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* curr = root;
        while (curr) {
            Node* dummy = new Node(-1);
            Node* succ = dummy;
            while (curr) {
                if (curr->left) {
                    succ->next = curr->left;
                    succ = succ->next;
                }
                if (curr->right) {
                    succ->next = curr->right;
                    succ = succ->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
        }
        return root;
    }
};