class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (!set.count(endWord)) {
            return 0;
        }
        if (set.count(beginWord)) {
            set.erase(beginWord);
        }
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while (!q.empty()) {
            ++len;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                if (curr == endWord) {
                    return len;
                }
                q.pop();
                for (int j = 0; j < curr.size(); ++j) {
                    char ori = curr[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        curr[j] = c;
                        if (set.count(curr)) {
                            set.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = ori;
                }
            }
        }
        return 0;
    }
};