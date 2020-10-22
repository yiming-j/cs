class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size = S.size();
        vector<int> last(26, -1);
        vector<int> starts;
        for (int i = 0; i < size; ++i) {
            if (starts.empty() || last[S[i] - 'a'] == -1) {
                starts.emplace_back(i);
            } else {
                while (last[S[i] - 'a'] < starts.back()) {
                    starts.pop_back();
                }
            }
            last[S[i] - 'a'] = i;
        }
        vector<int> ans;
        for (int i = 0; i < starts.size() - 1; ++i) {
            ans.emplace_back(starts[i + 1] - starts[i]);
        }
        ans.emplace_back(size - starts.back());
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size = S.size();
        vector<int> last(26, -1);
        for (int i = 0; i < size; ++i) {
            last[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> ans;
        for (int i = 0; i < size; ++i) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};