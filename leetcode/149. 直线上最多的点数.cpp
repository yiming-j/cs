class Solution {
private:
    int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m % n);
    }
    
    pair<int, int> slope(const vector<int>& p1, const vector<int>& p2) {
        int dy = p2[1] - p1[1];
        int dx = p2[0] - p1[0];
        if (dy == 0) {
            return {p1[1], 0};
        }
        if (dx == 0) {
            return {0, p1[0]};
        }
        int d = gcd(dy, dx);
        return {dy / d, dx / d};
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> map;
            const auto &p1 = points[i];
            int samePoints = 1;
            int maxPoints = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                const auto &p2 = points[j];
                if (p1 == p2) {
                    ++samePoints;
                } else {
                    maxPoints = max(maxPoints, ++map[slope(p1, p2)]); 
                }
            }
            ret = max(ret, maxPoints + samePoints);
        }
        return ret;
    }
};