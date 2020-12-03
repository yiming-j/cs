class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        int leftMax = height[0];
        vector<int> left(n, 0);
        for (int i = 1; i < n; ++i) {
            leftMax = max(leftMax, height[i]);
            left[i] = leftMax - height[i];
        }
        int rightMax = height[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            rightMax = max(rightMax, height[i]);
            left[i] = min(rightMax - height[i], left[i]);
        }
        return accumulate(left.begin(), left.end(), 0);
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