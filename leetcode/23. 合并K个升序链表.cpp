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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* lhs, const ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (const auto list : lists) {
            if (list) {
                pq.push(list);                
            }
        }
        unique_ptr<ListNode> dummy(new ListNode());
        ListNode* curr = dummy.get();
        while (!pq.empty()) {
            ListNode* node = pq.top();
            curr->next = node;
            curr = curr->next;
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};

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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        l2->next = merge(l1, l2->next);
        return l2;
    }
    
    ListNode* mergeSort(vector<ListNode*>& lists, int lo, int hi) {
        if (lo == hi) {
            return lists[lo];
        }
        int mi = lo + (hi - lo) / 2;
        ListNode* l1 = mergeSort(lists, lo, mi);
        ListNode* l2 = mergeSort(lists, mi + 1, hi);
        return merge(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size() - 1);
    }
};

