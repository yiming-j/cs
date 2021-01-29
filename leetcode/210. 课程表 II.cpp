class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> graph(numCourses);
        for (const auto &pre : prerequisites) {
            ++indegrees[pre[0]];
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> ret;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto src = q.front();
            q.pop();
            ret.push_back(src);
            for (const auto &dest : graph[src]) {
                if (--indegrees[dest] == 0) {
                    q.push(dest);
                }
            }
        }
        return ret.size() == numCourses ? ret : vector<int>();
    }
};