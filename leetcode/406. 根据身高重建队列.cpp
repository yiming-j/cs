class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
             [](const vector<int>& l, const vector<int> &r) {
                 return l[0] == r[0] ? l[1] > r[1] : l[0] < r[0];
             });
        int size = people.size();
        vector<vector<int>> ans(size);
        for (int i = 0; i < size; ++i) {
            vector<int> curr = people[i];
            int blank = curr[1] + 1;
            for (int j = 0; j < size; ++j) {
                if (!ans[j].empty()) {
                    continue;
                }
                if (--blank == 0) {
                    ans[j] = curr;
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
             [](const vector<int>& l, const vector<int> &r) {
                 return l[0] == r[0] ? l[1] < r[1] : l[0] > r[0];
             });
        int size = people.size();
        vector<vector<int>> ans;
        for (int i = 0; i < size; ++i) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};