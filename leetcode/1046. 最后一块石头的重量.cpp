class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const int& stone: stones) {
            pq.push(stone);
        }
        while (pq.size() >= 2) {
            int n1 = pq.top(); pq.pop();
            int n2 = pq.top(); pq.pop();
            if (n1 > n2) {
                pq.push(n1 - n2);
            }
        }
        if (!pq.empty()) {
            return pq.top();
        }
        return 0;
    }
};