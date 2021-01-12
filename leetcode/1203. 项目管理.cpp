class Solution {
private:
    vector<int> topoSort(vector<int> &indegrees, vector<vector<int>> &adj, vector<int> &nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> ret;
        queue<int> q;
        for (const auto &num : nums) {
            if (indegrees[num] == 0) {
                q.push(num);
            }
        }
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            ret.push_back(src);
            for (const auto &dest : adj[src]) {
                if (--indegrees[dest] == 0 && set.count(dest)) {
                    q.push(dest);
                }
            }
        }
        return ret.size() == nums.size() ? ret : vector<int>();
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItem(m);
        for (int i = 0; i < group.size(); ++i) {
            if (group[i] == -1) {
                group[i] = m++;
                groupItem.push_back({i});
            } else {
                groupItem[group[i]].push_back(i);
            }
        }   
        vector<int> itemIndegrees(n);
        vector<vector<int>> itemAdj(n);
        vector<int> groupIndegrees(m);
        vector<vector<int>> groupAdj(m);
        for (int i = 0; i < beforeItems.size(); ++i) {
            for (const auto &item : beforeItems[i]) {
                itemIndegrees[i] += 1;
                itemAdj[item].push_back(i);
                if (group[i] != group[item]) {
                    groupIndegrees[group[i]] += 1;
                    groupAdj[group[item]].push_back(group[i]);                    
                }
            }
        }
        

        vector<int> oriGroup(m);
        iota(oriGroup.begin(), oriGroup.end(), 0);
        vector<int> sortedGroup = topoSort(groupIndegrees, groupAdj, oriGroup);
        vector<int> ret;
        for (const auto &g : sortedGroup) {
            vector<int> sortedItem = topoSort(itemIndegrees, itemAdj, groupItem[g]);
            for (const auto &item : sortedItem) {
                ret.push_back(item);
            }
        }
        return ret.size() == n ? ret : vector<int>();
    }
};
