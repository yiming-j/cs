class UnionFindSet {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
public:
    const string& Find(const string &s) {
        if (s != parent[s]) {
            parent[s] = Find(parent[s]);
        }
        return parent[s];
    }
    
    void Union(const string &s1, const string &s2) {
        if (parent.find(s1) == parent.end()) {
            parent[s1] = s1;
            rank[s1] = 0;
        }
        if (parent.find(s2) == parent.end()) {
            parent[s2] = s2;
            rank[s2] = 0;
        }
        const string &p1 = Find(s1), &p2 = Find(s2);
        if (p1 == p2) {
            return;
        } 
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p2] = p1;
            ++rank[p1];
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        UnionFindSet ufset;
        for (const auto &pair : pairs) {
            ufset.Union(pair[0], pair[1]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (ufset.Find(words1[i]) != ufset.Find(words2[i])) {
                return false;
            }
        }
        return true;
    }
};