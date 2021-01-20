class UFSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UFSet(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            ++rank[pu];
        }
    } 
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int count = 0;
        for (const auto &account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                if (emailToIndex.count(account[i])) {
                    continue;
                }
                emailToIndex[account[i]] = count++;
                emailToName[account[i]] = account[0];
            }
        }
        UFSet ufs(count);
        for (const auto &account : accounts) {
            int firstIdx = emailToIndex[account[1]];
            for (int i = 2; i < account.size(); ++i) {
                int secondIdx = emailToIndex[account[i]];
                ufs.merge(firstIdx, secondIdx);
            }
        }
        unordered_map<int, vector<string>> indexToEmails;
        for (const auto &kv : emailToIndex) {
            indexToEmails[ufs.find(kv.second)].push_back(kv.first);
        }
        vector<vector<string>> ret;
        for (auto &kv : indexToEmails) {
            vector<string> &temp = kv.second;
            sort(temp.begin(), temp.end());
            vector<string> curr;
            curr.emplace_back(emailToName[temp[0]]);
            curr.insert(curr.end(), temp.begin(), temp.end());
            ret.emplace_back(curr);
        }
        return ret;
    }
};