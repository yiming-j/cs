class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        if (dead.count(string("0000"))) {
            return -1;
        }
        queue<string> q;
        q.push(string("0000"));
        visited.insert(string("0000"));
        int ret = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                if (curr == target) {
                    return ret;
                }
                q.pop();
                string temp;
                for (int j = 0; j < 4; ++j) {
                    temp = curr;
                    temp[j] = temp[j] == '9' ? '0' : temp[j] + 1;
                    if (!dead.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push(temp);
                    }
                    temp = curr;
                    temp[j] = temp[j] == '0' ? '9' : temp[j] - 1;
                    if (!dead.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
            ++ret;
        }
        return -1;
    }
};