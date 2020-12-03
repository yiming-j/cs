class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = s.empty() ? 0 : s.top();
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();
                ans = max(ans, height * (r - l));
            }
            s.push(i);
        }
        int r = s.empty() ? 0 : s.top();
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int l = s.empty() ? -1 : s.top();
            ans = max(ans, height * (r - l));
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && height[s.top()] <= height[i]) {
                int h = height[s.top()];
                int r = height[i];
                s.pop();
                int w = s.empty() ? 0 : i - s.top() - 1;
                int l = s.empty() ? 0 : height[s.top()];
                ans += (min(l, r) - h) * w;
            }
            s.push(i);
        }
        return ans;
    }
};