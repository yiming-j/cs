class Solution {
private:
    unordered_map<string, unordered_map<string, double>> edge;
    unordered_set<string> visited;
    
    double dfs(const string& src, const string& dest) {
        if (src == dest) {
            return 1;
        }
        if (edge[src].count(dest)) {
            return edge[src][dest];
        }
        visited.insert(src);
        for (auto &e : edge[src]) {
            if (visited.count(e.first)) {
                continue;
            }
            double d = dfs(e.first, dest);
            if (d > 0) {
                edge[src][dest] = d * e.second;
                edge[dest][src] = 1 / (d * e.second);
                break;
            }
        }
        visited.erase(src);
        if (!edge[src].count(dest)) {
            return -1;
        }
        return edge[src][dest];
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            edge[equations[i][0]][equations[i][1]] = values[i];
            edge[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> ret;
        for (const auto &q : queries) {
            if (!edge.count(q[0]) || !edge.count(q[1])) {
                ret.push_back(-1.0);
                continue;
            }
            ret.push_back(dfs(q[0], q[1]));
        }
        return ret;
    }
};