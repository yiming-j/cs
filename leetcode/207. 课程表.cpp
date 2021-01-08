class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (const auto &pre : prerequisites) {
            ++indegrees[pre[1]];
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int src = q.front();
            --numCourses;
            q.pop();
            for (const auto &dest : adj[src]) {
                if (--indegrees[dest] == 0) {
                    q.push(dest);
                }
            }
        }
        return !numCourses;
    }
};