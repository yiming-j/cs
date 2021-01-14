class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        queue<int> q;
        int count = 1;
        visited[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const auto &key : rooms[curr]) {
                if (visited[key]) {
                    continue;
                }
                ++count;
                visited[key] = 1;
                q.push(key);
            }
        }
        return count == rooms.size();
    }
};